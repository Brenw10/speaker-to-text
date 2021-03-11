import speech_recognition as sr

def getAudioText(filepath):
    with sr.AudioFile(filepath) as source:
        r = sr.Recognizer()
        audio_data = r.record(source)
        text = r.recognize_google(audio_data)
        return text

print(getAudioText("sounds/test.wav"))