import os
import numpy as np

def create_data_directory():
    current_dir = os.path.dirname(__file__)
    parent_dir = os.path.dirname(current_dir)
    data_path = os.path.join(parent_dir, "data")
    if not os.path.exists(data_path):
        os.mkdir(data_path)
    return data_path

def get_time_difference(timediff_file_path):
    timediff_array = np.array([])  # Define the array inside the function
    with open(timediff_file_path, "r") as f:
        for line in f:
            # Remove the string "Time difference: " from each line and convert the remaining part to a floating point number
            timediff = float(line.strip().replace("Time difference: ", "").split()[0])
            # Append the time difference to the array
            timediff_array = np.append(timediff_array, timediff)
    
    # Calculate the average of the first 1000 elements of the array (or fewer if the array has less than 1000 elements)
    average_timediff = np.mean(timediff_array[:1000])
    return average_timediff

if __name__ == '__main__':
    data_path = create_data_directory()
    timediff_file_path = os.path.join(data_path, "timediff.txt")
    
    # Check if the file exists before attempting to read it
    if os.path.exists(timediff_file_path):
        average_timediff = get_time_difference(timediff_file_path)
        print(average_timediff)
    else:
        print(f"File {timediff_file_path} does not exist.")
