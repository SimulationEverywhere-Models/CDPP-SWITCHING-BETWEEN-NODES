[top]
components : switch@Switch
in : switchIn
out : switchOut1
out : switchOut2
out : gateWay
Link : switchIn switchIn@switch
Link : switchOut1@switch switchOut1
Link : switchOut2@switch switchOut2
Link : gateWay@switch gateWay

[switch]
preparation : 00:00:01:000
 