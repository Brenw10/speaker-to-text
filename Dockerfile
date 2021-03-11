FROM python:3.8

ENV APP=/home/app
WORKDIR $APP

COPY . $APP

RUN pip install -r requirements.txt

CMD [ "python", "main.py" ]