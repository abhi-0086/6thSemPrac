#write a program to find the hash of a file & display it

import hashlib
def hashFile(filename):
    # this function return the SHA1 hash of the file passed into it
    #make a hash object
    hash_object = hashlib.sha1()

    #open file for reading in binary mode
    with open(filename, 'rb') as file:
        #loop till end of file
        while True:
            chunk = file.read(1024)
            if not chunk:
                break
            hash_object.update(chunk)
    
    return hash_object.hexdigest()

#main function
message = hashFile("body.txt")
print(message)