# sudo pip3 install Pillow
from PIL import Image
import argparse
import os


def img_resize(im_input, im_output, width, height):
    im = Image.open(im_input)
    (x,y) = im.size
    print((x,y))
    out = im.resize((width, height), Image.ANTIALIAS)
    out.save(im_output)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="An image process tool.")    
    parser.add_argument("-i", "--input", help="input image file")
    parser.add_argument("-o", "--output", help="output image file")
    parser.add_argument("-d", "--dir", help="directory")
    parser.add_argument("-g", "--height", type=int, help="directory")
    parser.add_argument("-w", "--width", type=int, help="directory")
    args = parser.parse_args()

    if args.input:
        if args.output:
            img_resize(args.input, args.output, 500, 309)
        else:
            img_resize(args.input, args.input, 500, 309)

    if args.dir:
        for rt, dirs, files in os.walk(args.dir):
            for f in files:
                if os.path.splitext(f)[-1] == '.jpg':
                    pf = os.path.join(rt, f)
                    print(pf)
                    # img_resize(pf, pf, 800, 609)
                    img_resize(pf, pf, args.width, args.height)
