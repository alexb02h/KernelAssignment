cmd_/home/alexander/src/Module.symvers := sed 's/\.ko$$/\.o/' /home/alexander/src/modules.order | scripts/mod/modpost -m -a  -o /home/alexander/src/Module.symvers -e -i Module.symvers   -T -
