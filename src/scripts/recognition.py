import sys
import speech_recognition as sr

r = sr.Recognizer()

try:
  with sr.AudioFile(sys.argv[1]) as source:
    audio_data = r.record(source)
    text = r.recognize_google(audio_data)
    print(text)
except:
  print()