[top]
components : sink@Sink
in : sinkIn
out : packetsReceived
Link : sinkIn sinkIn@sink
Link : packetsReceived@sink packetsReceived


[sink]
preparation : 00:00:01:000
address : 0 