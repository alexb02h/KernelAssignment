cmd_/home/alexander/helloworld/modules.order := {   echo /home/alexander/helloworld/hello.ko; :; } | awk '!x[$$0]++' - > /home/alexander/helloworld/modules.order
