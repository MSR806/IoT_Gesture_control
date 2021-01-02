import serial                                      # Serial library for serial communication
import pyautogui                                   # pyautogui library for controlling the mouse and keyboard.

Arduino_Serial = serial.Serial('com8',9600)

while 1:
        serialInput = str (Arduino_Serial.readline())

        if "LeftFar" in serialInput:
                pyautogui.keyDown('alt')  # hold down the alt key
                pyautogui.press('tab')
                print('LF')
                serialInput = str (Arduino_Serial.readline())
                if "LF0" in serialInput:
                        pyautogui.keyUp('alt')  # release the alt key
        if "LeftNear" in serialInput:
                pyautogui.keyDown('ctrl')  # hold down the ctlr key
                pyautogui.press('tab')
                print('LN')
                serialInput = str (Arduino_Serial.readline())
                if "LN0" in serialInput:
                        pyautogui.keyUp('ctrl')  # release the alt key
        if "RightFar" in serialInput:
                pyautogui.press('volumeup')
                print('RF')
        if "RightNear" in serialInput:
                pyautogui.press('volumedown')
                print('RN')
