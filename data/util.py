import os
import numpy as np

def read_timediff_file(file_path):
    """
    Read the time difference file and return the average of the first 1000 time differences.
    
    Parameters:
        file_path (str): The path to the time difference file.
        
    Returns:
        float: The average of the first 1000 time differences.
    """
    # Create an empty array using NumPy
    timediff_array = np.array([])
    
    # Read the file line by line and parse the numbers
    with open(file_path, "r") as f:
        for line in f:
            # Remove the string "Time difference: " from each line and convert the remaining part to a floating point number
            timediff = float(line.strip().replace("Time difference: ", "").split()[0])
            # Append the time difference to the array
            timediff_array = np.append(timediff_array, timediff)
    
    # Calculate the average of the array
    average_timediff = np.mean(timediff_array[:1000])
    return average_timediff

if __name__ == '__main__':
    current_dir = os.path.dirname(__file__)
    timediff_file_path = os.path.join(current_dir, "timediff.txt")
    
    # Check if the file exists before attempting to read it
    if os.path.exists(timediff_file_path):
        average_timediff = read_timediff_file(timediff_file_path)
        print("Average time difference:", average_timediff)
    else:
        print(f"File {timediff_file_path} does not exist.")
