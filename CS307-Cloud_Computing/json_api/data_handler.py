#!/usr/local/bin/python3.8
import os

import dotenv


def handle_instance_data(filename, import_data=False, export_data=False):
    '''Load and/or save data to/from an EC2 instance.

    Args:
        filename (str): absolute or relative path to a JSON file.
        import_data (bool): Optional. Retrieves last saved JSON data from EC2 instance.
        export_data (bool): Optional. Saves JSON data to EC2 instance.
    
    Returns:
        None.
    '''
    dotenv.load_dotenv()
    secret_key = os.getenv("SECRET_KEY")
    ec2_instance = os.getenv("EC2_INSTANCE")
    if export_data:
        os.system('scp -i {secret_key} {filename} {ec2_instance}'.format(
            secret_key=secret_key, filename=filename, ec2_instance=ec2_instance
        ))
    if import_data:
        os.system('scp -i {secret_key} {ec2_instance} {filename}'.format(
            secret_key=secret_key, ec2_instance=ec2_instance, filename=filename
        ))


def load_json_data(filename):
    '''Opens a JSON file and converts the data into a dict.

    Args:
        filename (str): absolute or relative path to a JSON file.

    Returns:
        dict: Dictionary representing JSON file data.
    '''
    handle_instance_data(filename, import_data=True)
    json_data = {}
    with open(filename, 'r') as json_file:
        json_data = json.load(json_file)
    return json_data


def write_json_data(filename, json_data):
    '''Creates and saves a new JSON file using a preexisting dict.

    Args:
        filename (str): absolute or relative path to a JSON file.
        json_data (dict): data to be written to the JSON file.

    Returns:
        None.
    '''
    with open(filename, 'w') as json_file:
        json.dump(json_data, json_file)
    handle_instance_data(filename, export_data=True)

if __name__ == '__main__':
    handle_instance_data('data.json', True, True)