#write a program to mail merge

# names are in the names.txt
# body of the mail is in body.txt



#open names.txt for reading
with open("names.txt", 'r', encoding='utf-8') as names_file:

    #open body.txt for reading
    with open("body.txt", 'r', encoding='utf-8') as body_file:

        #read the entire content of body file
        body = body_file.read()

        #iterates over names
        for name in names_file:
            mail = "Hello " + name.strip() + "\n" + body

            #write the mails to individual file
            with open(name.strip() + ".txt", 'w', encoding='utf-8') as mail_file:
                mail_file.write(mail)





# import os

# # Get the absolute paths to the names and body files
# names_file_path = os.path.abspath("names.txt")
# body_file_path = os.path.abspath("body.txt")

# # Open the names file for reading
# try:
#     with open(names_file_path, 'r', encoding='utf-8') as names_file:

#         # Open the body file for reading
#         with open(body_file_path, 'r', encoding='utf-8') as body_file:

#             # Read the contents of the body file
#             body = body_file.read()

#             # Iterate over each name in the names file
#             for name in names_file:
#                 # Generate the email body
#                 mail = "Hello " + name.strip() + ",\n" + body

#                 # Write the email body to a file
#                 email_file_path = os.path.abspath(name.strip() + ".txt")
#                 with open(email_file_path, 'w', encoding='utf-8') as email_file:
#                     email_file.write(mail)

# except Exception as e:
#     print("An error occurred: ", e)
