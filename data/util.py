import os
import numpy as np


timediff_file_path = "timediff.txt"

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
