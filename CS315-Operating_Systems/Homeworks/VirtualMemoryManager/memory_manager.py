def update_tlb(page_number, frame_number, tlb):
    tlb.append([page_number, frame_number])
    # FIFO method, remove earliest entry
    if len(tlb) > 16:
        tlb.pop(0)


def update_page_table(page_number, frame_number, page_table):
    page_table.append([page_number, frame_number])
    # FIFO method, remove earliest entry
    if len(page_table) > 256:
        page_table.pop(0)


def page_fault_handler(page_number, tlb, page_table, physical_memory):
    if page_number < 256:
        for i in range(256):
            if i not in physical_memory.keys():
                frame_number = i
                break
        backing_store = open("BACKING_STORE.bin", "rb")
        physical_memory[frame_number] = []
        for i in range(256):
            backing_store.seek(page_number * 256 + i)
            data = str(int.from_bytes(
                backing_store.read(1), byteorder="big", signed=True
            ))
            physical_memory[frame_number].insert(i, data)
        backing_store.close()
        print("Found page # {}".format(page_number))
        update_tlb(page_number, frame_number, tlb)
        update_page_table(page_number, frame_number, page_table)
    else:
        print("Page # {} is out of bounds".format(page_number))


def update_tlb_counter(latest_entry_index, tlb):
    # Update TLB with new sequence using LRU
    latest_entry = tlb[latest_entry_index]
    tlb.pop(latest_entry_index)
    tlb.append(latest_entry)


def update_page_table_counter(latest_entry_index, page_table):
    # Update Page Table with new sequence using LRU
    latest_entry = page_table[latest_entry_index]
    page_table.pop(latest_entry_index)
    page_table.append(latest_entry)


def read_physical_memory(frame_number, offset, physical_memory):
    if frame_number < 256 and offset < 256:
        data = physical_memory[frame_number][offset]
        print("{} in physical memory".format(data))
        return data
    else:
        print("Frame number or offset is out of bounds")


def check_tlb(page_number, physical_memory, offset, logical_address, tlb,
    address_read_counter, output_file):
    for j in range(len(tlb)):
        if page_number == tlb[j][0]:
            print("Page # {} found in TLB".format(page_number))
            frame_number = tlb[j][1]
            data = read_physical_memory(frame_number, offset, physical_memory)
            physical_address = "{0:08b}{0:08b}".format(frame_number, offset)
            physical_address = int(physical_address, base=2)
            output = []
            output.append("{:>4} | Virtual Address: {:>5} | ".format(
                address_read_counter, logical_address))
            output.append("Physical Address: {:>5} | ".format(physical_address))
            output.append("Value: {}\n".format(data))
            output = "".join(output)
            output_file.write(output)
            update_tlb_counter(j, tlb)
            return True
    return False


def check_page_table(page_number, logical_address, offset, address_read_counter,
    page_table, physical_memory, output_file):
    for k in range(len(page_table)):
        if page_number == page_table[k][0]:
            print("Page # {} found in Page Table".format(page_number))
            frame_number = page_table[k][1]
            data = read_physical_memory(frame_number, offset, physical_memory)
            physical_address = "{0:08b}{0:08b}".format(frame_number, offset)
            physical_address = int(physical_address, 2)
            output = []
            output.append("{:>4} | Virtual Address: {:>5} | ".format(
                address_read_counter, logical_address))
            output.append("Physical Address: {:>5} | ".format(physical_address))
            output.append("Value: {}\n".format(data))
            output = "".join(output)
            output_file.write(output)
            update_page_table_counter(k, page_table)
            return True
    return False


if __name__ == '__main__':
    physical_memory = {}
    tlb = []
    page_table = []
    page_fault_counter = 0
    tlb_hit_counter = 0
    address_read_counter = 0
    output_file = open("output.txt", "w")
    with open("addresses.txt", "r") as address_file:
        for line in address_file:
            tlb_hit = False
            page_table_true = False
            logical_address = int(line)
            # Compare logical address binary with binary value of 255 to get
            # offset
            offset = logical_address & 255
            # Compare logical address binary with binary value of 65280
            # 65280 is physical memory size (65536) - 256 byte frame size
            page_original = logical_address & 65280
            # Use right bit shift operator to shift page original by 8 bits
            page_number = page_original >> 8
            address_read_counter += 1
            tlb_hit = check_tlb(page_number, physical_memory, offset,
                logical_address, tlb, address_read_counter, output_file
                )
            if tlb_hit:
                tlb_hit_counter += 1
            else:
                page_table_true = check_page_table(page_number, logical_address,
                offset, address_read_counter, page_table, physical_memory,
                output_file
                )
            if not page_table_true and not tlb_hit:
                print("Page Fault Found")
                page_fault_handler(
                    page_number, tlb, page_table, physical_memory
                    )
                page_fault_counter += 1
                tlb_hit = check_tlb(page_number, physical_memory, offset,
                    logical_address, tlb, address_read_counter, output_file)
                if tlb_hit:
                    tlb_hit_counter += 1
    page_fault_rate = page_fault_counter / address_read_counter
    tlb_hit_rate = tlb_hit_counter / address_read_counter
    # Write results to txt file
    output = []
    output.append("-" * 80)
    output.append("Number of translated addresses: {}".format(
        address_read_counter))
    output.append("Number of page faults: {}".format(page_fault_counter))
    output.append("Page fault rate: {}".format(page_fault_rate))
    output.append("Number of TLB hits: {}".format(tlb_hit_counter))
    output.append("TLB hit rate: {}".format(tlb_hit_rate))
    output = "\n".join(output)
    output_file.write(output)
    output_file.close()
