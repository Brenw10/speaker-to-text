import subprocess
import os
import speech_recognition as sr
from pydub import AudioSegment

r = sr.Recognizer()

def convertToWav(filepath):
  AudioSegment.from_wav(filepath).export(filepath, format=extension)

def getTextFromAudio(filepath):
  with sr.AudioFile(filepath) as source:
    audio_data = r.record(source)
    text = r.recognize_google(audio_data)
    return text

def createDirectory(directory):
  if not os.path.exists(directory):
    os.makedirs(directory)
  
directory = 'sounds'
extension = 'wav'
filepath = directory + '/output.' + extension

createDirectory(directory)

while True:
  try:
    subprocess.call("main.exe " + filepath)
    convertToWav(filepath)
    text = getTextFromAudio(filepath)
    print(text)
  except Exception as err:
    print(err)