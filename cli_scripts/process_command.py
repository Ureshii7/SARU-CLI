import sys
import logging
from flair.models import TextClassifier
from flair.data import Sentence

print(f"Input received: {sys.argv[1]}")

# Set up logging
logging.basicConfig(filename="saru-cli.log", level=logging.DEBUG, format='%(asctime)s - %(message)s')

# Load the pre-trained NLP model (you can replace this with your own trained model)
classifier = TextClassifier.load('en-sentiment')  # Placeholder model; replace with your custom model

# Get the user input from the Bash script
user_input = sys.argv[1]

# Log user input for debugging
logging.info(f"Received user input: {user_input}")

try:
    # Process the input with Flair NLP
    sentence = Sentence(user_input)
    classifier.predict(sentence)

    # Handle different types of commands based on NLP response
    if 'file' in sentence.labels[0].value.lower():
        command = "ls"
    elif 'disk' in sentence.labels[0].value.lower():
        command = "df -h"
    else:
        command = "echo 'Command not recognized!'"

    # Log the chosen command
    logging.info(f"Command mapped to: {command}")

    # Return the appropriate command
    print(command)

except Exception as e:
    # Log any errors that occur during processing
    logging.error(f"Error processing user input: {str(e)}")
    print("Command not recognized!")
    sys.exit(1)
