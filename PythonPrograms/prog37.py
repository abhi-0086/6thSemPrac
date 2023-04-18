#write a progrm to find the size (resolution) of image

def image_res(filename):
    #this function pprints resolution of image passed to it
    
    #open image for reading in binary mode
    with open(filename, 'rb') as img_file:

        #height of image (in 2 bytes) is at 164th position
        img_file.seek(1050)

        #read the 2 bytes
        a = img_file.read(2)

        #calculate the height
        height = (a[0] << 8) + a[1]

        #next 2 bytes is width
        a = img_file.read(2)

        #calculate width
        width = (a[0] << 8) + a[1]
    
    print("The resolution of image is ", width, "x", height)

#main function
image_res("flower.jpg")