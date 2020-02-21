#!/usr/bin/python3

import collections
import time


class Job(object):
    def __init__(self, job_number, job_time, job_size):
        self.number = job_number
        self.time = job_time
        self.size = job_size
        self.running = False

    def run(self):
        self.running = True

    def stop(self):
        self.running = False


class Partition(object):
    def __init__(self, memory_number, memory_size):
        self.number = memory_number
        self.blocks = memory_size
        self.current_job = None
        self.busy = False
    
    def is_busy(self):
        return self.busy

    def load_job(self, job):
        if not self.busy:
            job.run()
            self.current_job = job
            self.busy = True

    def unload_job(self):
        if self.busy:
            self.current_job.stop()
            self.current_job = None
            self.busy = False

    def job_time_left(self):
        return self.current_job.time

    def decrease_cpu_time(self):
        if self.busy:
            self.current_job.time -= 1



class JobManager(object):
    def __init__(self, memory_list, job_list, sort_partitions=False):
        self.partitions = []
        self.largest_parition_size = 0
        for memory in memory_list:
            memory_number, memory_size = memory
            new_partition = Partition(memory_number, memory_size)
            if new_partition.blocks > self.largest_parition_size:
                self.largest_parition_size = new_partition.blocks
            self.partitions.append(new_partition)
        if sort_partitions:
            self.partitions = sorted(self.partitions, key=lambda partition : partition.blocks)
        self.jobs = []
        for job in job_list:
            job_number, job_time, job_size = job
            new_job = Job(job_number, job_time, job_size)
            self.jobs.append(new_job)

    def run_jobs(self):
        print('Running Jobs...')
        unrunnable_jobs = []
        wait_queue = collections.deque()
        incomplete_jobs = collections.deque(self.jobs)
        while incomplete_jobs:
            if len(wait_queue) == 0:
                job = incomplete_jobs.popleft()
                print('Finding memory for job #{}...'.format(job.number))
            else:
                job = wait_queue.popleft()
                print('Removing job#{} from wait queue, attempting to find memory...'.format(job.number))
            partition_found = False
            for partition in self.partitions:
                if partition.blocks >= job.size and not (partition.is_busy()):
                    print('Loading job #{} into partition #{}'.format(job.number, partition.number))
                    partition.load_job(job)
                    partition_found = True
                    break
            for partition in self.partitions:
                if partition.is_busy():
                    if partition.job_time_left() == 0:
                        partition.unload_job()
                    else:
                        partition.decrease_cpu_time()
            time.sleep(0.5)
            if not partition_found:
                if job.size > self.largest_parition_size:
                    print('Job #{} is larger than all available partitions!'.format(job.number))
                    unrunnable_jobs.append(job)
                else:
                    print('No partitions with enough blocks found...adding job #{} into wait queue...'.format(job.number))
                    wait_queue.append(job)
        if unrunnable_jobs:
            print('These jobs could not be run due to insufficient partition block size:\n')
            print(', '.join(list(map(lambda number: 'Job #{}'.format(number), [job.number for job in unrunnable_jobs]))))
        else:
            print('All jobs completed')


def parse_input_data(filename):
    data = []
    with open(filename, 'r') as file:
        for line in file.readlines():
            entry = tuple(map(int, line.strip('\n').split(' ')))
            data.append(entry)
    return data


if __name__ == '__main__':
    memory_list = parse_input_data('memory_list.txt')
    job_list = parse_input_data('job_list.txt')
    job_manager = JobManager(memory_list, job_list, sort_partitions=True)
    job_manager.run_jobs()
