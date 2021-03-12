import subprocess
import os
import speech_recognition as sr
from pydub import AudioSegment

executable = 'main.exe'
directory = 'sounds'
extension = 'wav'
filename = 'output'
filenameNew = 'output2'
filepath = directory + '/' + filename + '.' + extension
filepathNew = directory + '/' + filenameNew + '.' + extension

r = sr.Recognizer()

def create_directory(directory):
  if not os.path.exists(directory):
    os.makedirs(directory)

def record_system_audio(filepath):
  subprocess.call(executable + " " + filepath)

def convert_to_wav(frompath, topath):
  AudioSegment.from_wav(frompath).export(topath, format=extension)

def get_text_from_audio(filepath):
  with sr.AudioFile(filepath) as source:
    audio_data = r.record(source)
    text = r.recognize_google(audio_data)
    return text

if __name__ == '__main__':
  create_directory(directory)
  while True:
    try:
      record_system_audio(filepath)
      convert_to_wav(filepath, filepath)
      text = get_text_from_audio(filepath)
      print(text)
    except Exception as err:
      print(err)