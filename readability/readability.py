text = input("Text: ")

# Counts the number of sentences in the input


def count_sentences(text):
    sentence_count = 0
    for i in range(len(text)):
        if text[i] in ['.', '!', '?']:  # Checks if 'i' is one of the elements in the array
            sentence_count += 1
    return sentence_count

# Counts the number of letters in the input


def count_letters(text):
    letter_count = 0
    for i in range(len(text)):
        if (text[i] >= 'A' and text[i] <= 'Z') or (text[i] >= 'a' and text[i] <= 'z'):  # Checks if the character in 'i' is a letter
            letter_count += 1

    return letter_count


word_count = len(text.split())
letter_count = count_letters(text)
sentence_count = count_sentences(text)

L = 100 * letter_count / word_count
S = 100 * sentence_count / word_count

grade = round(0.0588 * L - 0.296 * S - 15.8)

if grade > 16:
    print("Grade 16+")

elif grade < 1:
    print("Before Grade 1")

else:
    print(f"Grade {grade}")
