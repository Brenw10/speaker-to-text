import speech_recognition as sr

def getTextFromAudio(filepath):
    with sr.AudioFile(filepath) as source:
        r = sr.Recognizer()
        audio_data = r.record(source)
        text = r.recognize_google(audio_data)
        return text

print(getTextFromAudio("sounds/output.wav"))