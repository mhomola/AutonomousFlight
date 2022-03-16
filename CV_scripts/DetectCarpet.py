
def detect_carpet(pixel, image):
    height = int(len(image) * 0.6)
    index = pixel[0]
    status = True
    while index < height and status:
        index += 3

