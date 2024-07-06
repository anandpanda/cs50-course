from cs50 import get_string

# Get input text
text = get_string("Text: ")

# Initialize counters
letters = sum(1 for char in text if char.isalpha())
words = sum(1 for char in text if char.isspace()) + 1
sentences = sum(1 for char in text if char in ".!?")

# Calculate L and S
l = letters / words * 100
s = sentences / words * 100

# Calculate the Coleman-Liau index
index = round(0.0588 * l - 0.296 * s - 15.8)

# Print the grade level
if index >= 16:
    print("Grade 16+")
elif index >= 1:
    print(f"Grade {index}")
else:
    print("Before Grade 1")
