FROM python:3.8

ENV APP=/home/app
WORKDIR $APP

COPY . $APP

RUN apt-get update
RUN apt-get install libasound-dev portaudio19-dev libportaudio2 libportaudiocpp0 -y
RUN apt-get install python3-pyaudio -y

RUN pip install -r requirements.txt

CMD [ "python", "main.py" ]