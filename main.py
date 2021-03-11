import subprocess
import os
import speech_recognition as sr

directory = 'sounds'
filepath = directory + '/output.wav'
r = sr.Recognizer()

def getTextFromAudio(filepath):
  with sr.AudioFile(filepath) as source:
    audio_data = r.record(source)
    text = r.recognize_google(audio_data)
    return text

if not os.path.exists(directory):
  os.makedirs(directory)

subprocess.call("main.exe " + filepath)
text = getTextFromAudio(filepath)
print(text)