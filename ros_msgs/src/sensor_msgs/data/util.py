import os
import numpy as np

current_dir = os.path.dirname(__file__)
parent_dir = os.path.dirname(current_dir)
data_path = os.path.join(parent_dir, "data")
if not os.path.exists(data_path):
    os.mkdir(data_path)

timediff_file_path = os.path.join(data_path, "timediff.txt")

# Create an empty array using NumPy
timediff_array = np.array([])

# Read the file line by line and parse the numbers
with open(timediff_file_path, "r") as f:
    for line in f:
        # Remove the string "Time difference: " from each line and convert the remaining part to a floating point number
        timediff = float(line.strip().replace("Time difference: ", "").split()[0])
        # Append the time difference to the array
        timediff_array = np.append(timediff_array, timediff)
# Calculate the average of the array
average_timediff = np.mean(timediff_array[:1000])
print("Average time difference:", average_timediff)
