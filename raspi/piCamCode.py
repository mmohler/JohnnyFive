## Imports
import picamera
import picamera.array
import cv2
import cv2.cv as cv
import tesseract
import serial
from time import sleep as wait

## GVARS
cells = []
chars = []
confs = []

## Functions
def initCamera():
        camera = picamera.PiCamera()
        camera.resolution = (320, 240)
        camera.start_preview()
        wait(2)	
        return camera

def initTess():
        api = tesseract.TessBaseAPI()
        api.init(None, 'eng', tesseract.OEM_DEFAULT)
        api.SetPageSegMode(tesseract.PSM_SINGLE_CHAR)
        api.SetVariable('tessedit_char_whitelist','ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()1234567890')
        return api

def takePhoto(cam):
        stream = picamera.array.PiRGBArray(cam)
        cam.capture(stream, format='bgr')
        # At this point the image is available as stream.array
        return stream.array
    
def ocr(api, im):
        im = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
        im = cv2.equalizeHist(im)
        (thresh, im2) = cv2.threshold(equlz, 100, 255, cv2.THRESH_BINARY | cv2.THRESH_OTSU)
        tesseract.SetCvImage(im2, api)
        text = api.GetUTF8Text()
        conf = api.MeanTextConf()
        return [text, conf]

## Main Code
piCamera = initCamera()
arduino = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
tess = initTess()

while true:
        wait(0.1)
        inp = arduino.readline()
        if (inp == 'STOP'):
                break;
        if (inp > 0):
                ##TAKE A PIC AND ANALYZE
                img = takePhoto(piCamera)
                serial.write('ct')
                [text, conf] = ocr(tess, img)
                cells.append(int(inp))
                chars.append(text)
                confs.append(conf)

## AFTER STOP from Arduino
# Close out the file and write all the info
tess.end()
camera.stop_preview()
for i in length(cells):
        print(cells[i])
        print(', ')
        print(chars[i])
	
