import sys
from pydub import AudioSegment

AudioSegment.from_wav(sys.argv[1]).export(sys.argv[2], format='wav')