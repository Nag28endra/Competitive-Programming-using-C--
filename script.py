import pyautogui,time

time.sleep(5)
count = 50

while count>=1:
    pyautogui.write("hi bro")
    pyautogui.press("enter")
    count -=1