import random
import string


def generate_zuma_input():
    # Step 1: Generate the initial string with no three consecutive beads of the same color
    initial_string = []
    for _ in range(1 << 15):
        initial_string.append("AABB")

    # Step 2: Generate the operations
    operations = []
    for _ in range(1000):
        # Iterate through letters A to Z
        for letter in "CDEFGHIJKLMNOPQRSTUVWXYZ":
            operations.append(f"0 {letter}")  # Insert letter at position 0

    # Step 3: Join the initial string and operations to form the complete input
    initial_string_str = "".join(initial_string)
    operations_str = "\n".join(operations)

    return f"{initial_string_str}\n{1}\n{operations_str}"


input_data = generate_zuma_input()

# Output the generated input to check
print(input_data)  # Print the first 1000 characters to inspect (for large inputs)
