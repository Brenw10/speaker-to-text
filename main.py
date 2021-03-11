import speech_recognition as sr

r = sr.Recognizer()

def getTextFromAudio(filepath):
	with sr.AudioFile(filepath) as source:
		audio_data = r.record(source)
		text = r.recognize_google(audio_data)
		return text

print(getTextFromAudio("sounds/output.wav"))