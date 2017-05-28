import sys
import socket
HOST = 'localhost'    # The remote host
PORT = 50997          # The same port as used by the server

counterSetValue = 0;

argsLength = len(sys.argv)
if argsLength > 1:
    i = 0
    while i < argsLength:
        if sys.argv[i] == '-set':
            if i+1 < argsLength:
                i = i+1
                counterSetValue = int(sys.argv[i])
                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                    s.connect((HOST, PORT))
                    counterSetMsg = 'count:set:' + str(counterSetValue)
                    s.sendall(counterSetMsg.encode())
            else:
                print('-set option requires a number')
        else:
            if sys.argv[i] == '-countup':
                with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                    s.connect((HOST, PORT))
                    countUpMsg = 'count:up'
                    s.sendall(countUpMsg.encode())
            else:
                if sys.argv[i] == '-countdown':
                    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                        s.connect((HOST, PORT))
                        countDownMsg = 'count:down'
                        s.sendall(countDownMsg.encode())
                else:
                    if sys.argv[i] == '-reset':
                        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
                            s.connect((HOST, PORT))
                            resetMsg = 'count:reset'
                            s.sendall(resetMsg.encode())
        i = i+1

