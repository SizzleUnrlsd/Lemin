FROM epitechcontent/epitest-docker

RUN mkdir /lem_in
WORKDIR /lem_in
COPY . /lem_in

RUN ./coding_style-parser.py

CMD [ "make" ]
