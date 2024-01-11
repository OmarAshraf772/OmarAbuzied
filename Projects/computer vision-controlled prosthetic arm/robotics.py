#!/usr/bin/env python
# coding: utf-8

# In[1]:


get_ipython().system('pip install mediapipe')
get_ipython().system('pip install opencv-python')
get_ipython().system('pip install pyFirmata')
get_ipython().system('pip install numpy')


# In[1]:


import mediapipe as mp
import numpy as np
import cv2
import time
import pyfirmata
import math
import serial


# In[6]:


#board = pyfirmata.Arduino('COM6')
#servothumb = board.get_pin('d:3:s')
#servoind = board.get_pin('d:5:s')
#servomid = board.get_pin('d:6:s')
#servoring = board.get_pin('d:9:s')
#servopi = board.get_pin('d:10:s')

  

mp_drawing = mp.solutions.drawing_utils
mp_drawing_styles = mp.solutions.drawing_styles
mp_hands = mp.solutions.hands



# Webcam Setup
wCam, hCam = 640, 480
cam = cv2.VideoCapture(0)
cam.set(3,wCam)
cam.set(4,hCam)


with mp_hands.Hands(
    model_complexity=0,
    min_detection_confidence=0.5,
    min_tracking_confidence=0.5) as hands:

  while cam.isOpened():
    success, image = cam.read()

    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    results = hands.process(image)
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
    if results.multi_hand_landmarks:
      for hand_landmarks in results.multi_hand_landmarks:
        mp_drawing.draw_landmarks(
            image,
            hand_landmarks,
            mp_hands.HAND_CONNECTIONS,
            mp_drawing_styles.get_default_hand_landmarks_style(),
            mp_drawing_styles.get_default_hand_connections_style()
            )

    # multi_hand_landmarks method for Finding postion of Hand landmarks      
    lmList = []
    if results.multi_hand_landmarks:
      myHand = results.multi_hand_landmarks[0]
      for id, lm in enumerate(myHand.landmark):
        h, w, c = image.shape
        cx, cy = int(lm.x * w), int(lm.y * h)
        lmList.append([id, cx, cy])          

    # Assigning variables for Thumb and Index finger position
    if len(lmList) != 0:
      t1, t2 = lmList[4][1], lmList[4][2]
      i1, i2 = lmList[8][1], lmList[8][2]
      m1, m2 = lmList[12][1], lmList[12][2]
      r1, r2 = lmList[16][1], lmList[16][2]
      p1, p2 = lmList[20][1], lmList[20][2]
      t3, t4 = lmList[1][1], lmList[1][2]
      i3, i4 = lmList[5][1], lmList[5][2]
      m3, m4 = lmList[9][1], lmList[9][2]
      r3, r4 = lmList[13][1], lmList[13][2]
      p3, p4 = lmList[17][1], lmList[17][2]

      # Marking Thumb
      cv2.circle(image, (t1,t2),15,(255,255,255))  
      cv2.circle(image, (m3,m4),15,(255,255,255))   
      cv2.line(image,(t1,t2),(m3,m4),(255,0,0),3)
      lengthT = math.hypot(m3-t1,m4-t2)
      if lengthT < 50:
        cv2.line(image,(t1,t2),(m3,m4),(0,0,0),3)

      PosT = np.interp(lengthT, [50, 220], [0, 100])
      PosgripperT= (round(PosT))
      #print(Posgripper)
      converted_PosgripperT = str(PosgripperT)
      cv2.putText(image, str(PosgripperT), (50, 60), cv2.FONT_HERSHEY_COMPLEX, 2, (255, 0, 0))
      #cv2.line(image, 320, 320, (0,0,0), 2)
      ServoposT=(100-PosgripperT)
      print (ServoposT)
      #servothumb.write(ServoposT)
        
        # Marking Index finger
      cv2.circle(image, (i1,i2),15,(255,255,255))  
      cv2.circle(image, (i3,i4),15,(255,255,255))   
      cv2.line(image,(i1,i2),(i3,i4),(255,0,0),3)
      lengthI = math.hypot(i3-i1,i4-i2)
      if lengthI < 50:
        cv2.line(image,(i1,i2),(i3,i4),(0,0,0),3)

      
      PosI = np.interp(lengthI, [50, 220], [0, 100])
      PosgripperI= (round(PosI))
      #print(Posgripper)
      converted_PosgripperI = str(PosgripperI)
      cv2.putText(image, str(PosgripperI), (50, 100), cv2.FONT_HERSHEY_COMPLEX, 2, (255, 0, 0))
      #cv2.line(image, 320, 320, (0,0,0), 2)
      ServoposI=(100-PosgripperI)
      print (ServoposI)
      #servoind.write(ServoposI)
        
        # Marking middle finger
      cv2.circle(image, (m1,m2),15,(255,255,255))  
      cv2.circle(image, (m3,m4),15,(255,255,255))   
      cv2.line(image,(m1,m2),(m3,m4),(255,0,0),3)
      lengthM = math.hypot(m3-m1,m4-m2)
      if lengthM < 50:
        cv2.line(image,(m1,m2),(m3,m4),(0,0,0),3)

      
      PosM = np.interp(lengthM, [50, 220], [0, 100])
      PosgripperM= (round(PosM))
      #print(Posgripper)
      converted_PosgripperM = str(PosgripperM)
      cv2.putText(image, str(PosgripperM), (50, 140), cv2.FONT_HERSHEY_COMPLEX, 2, (255, 0, 0))
      #cv2.line(image, 320, 320, (0,0,0), 2)
      ServoposM=(100-PosgripperM)
      print (ServoposM)
      #servomid.write(ServoposM)
        
        # Marking ring finger
      cv2.circle(image, (r1,r2),15,(255,255,255))  
      cv2.circle(image, (r3,r4),15,(255,255,255))   
      cv2.line(image,(r1,r2),(r3,r4),(255,0,0),3)
      lengthR = math.hypot(r3-r1,r4-r2)
      if lengthR < 50:
        cv2.line(image,(r1,r2),(r3,r4),(0,0,0),3)

      
      PosR = np.interp(lengthR, [50, 220], [0, 100])
      PosgripperR= (round(PosR))
      #print(Posgripper)
      converted_PosgripperR = str(PosgripperR)
      cv2.putText(image, str(PosgripperR), (50, 180), cv2.FONT_HERSHEY_COMPLEX, 2, (255, 0, 0))
      #cv2.line(image, 320, 320, (0,0,0), 2)
      ServoposR=(100-PosgripperR)
      print (ServoposR)
      #servoring.write(ServoposR)
        
        # Marking pinky finger
      cv2.circle(image, (p1,p2),15,(255,255,255))  
      cv2.circle(image, (p3,p4),15,(255,255,255))   
      cv2.line(image,(p1,p2),(p3,p4),(255,0,0),3)
      lengthP = math.hypot(p3-p1,p4-p2)
      if lengthP < 50:
        cv2.line(image,(p1,p2),(p3,p4),(0,0,0),3)

      
      PosP = np.interp(lengthP, [50, 220], [0, 100])
      PosgripperP= (round(PosP))
      #print(Posgripper)
      converted_PosgripperP = str(PosgripperP)
      cv2.putText(image, str(PosgripperP), (50, 220), cv2.FONT_HERSHEY_COMPLEX, 2, (255, 0, 0))
      #cv2.line(image, 320, 320, (0,0,0), 2)
      ServoposP=(100-PosgripperP)
      print (ServoposP)
      #servopi.write(ServoposP)
      
        
    
    cv2.imshow('handDetector', image) 
    if cv2.waitKey(1) & 0xFF == ord('q'):
      break
cam.release()


# In[ ]:




