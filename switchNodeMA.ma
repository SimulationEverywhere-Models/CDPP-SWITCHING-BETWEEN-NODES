[top]
components : queue@Queue
components : switch@Switch

in : In
out : Out1
out : Out2
out : gateWay

Link : In in@queue
Link : out@queue switchIn@switch
Link : switchOut1@switch done@queue
Link : switchOut2@switch done@queue
Link : gateWay@switch done@queue
Link : switchOut1@switch Out1
Link : switchOut2@switch Out2
Link : gateWay@switch gateWay

[queue]
preparation : 00:00:03:000

[switch]
preparation : 00:00:02:000
