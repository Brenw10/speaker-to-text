import subprocess
import os
import speech_recognition as sr
from pydub import AudioSegment
from multiprocessing import Process

executable = 'main.exe'
directory = 'sounds'
extension = 'wav'

r = sr.Recognizer()

def create_directory(directory):
  if not os.path.exists(directory):
    os.makedirs(directory)

def record_system_audio(filepath):
  subprocess.call(executable + " " + filepath)

def convert_to_wav(frompath, topath):
  AudioSegment.from_wav(frompath).export(topath, format=extension)

def get_text_from_audio(filepath):
  try:
    with sr.AudioFile(filepath) as source:
      audio_data = r.record(source)
      text = r.recognize_google(audio_data)
      return text
  except:
    return

def read_output(filepath):
  convert_to_wav(filepath, filepath)
  text = get_text_from_audio(filepath)
  os.remove(filepath)
  print(text)

if __name__ == '__main__':
  create_directory(directory)

  i = 0
  while True:
    filepath = directory + '/' + str(i) + '.' + extension
    record_system_audio(filepath)
    p1 = Process(target=read_output, args=(filepath,))
    p1.start()
    i = i + 1
