#! /bin/bash

# some localization
UNDER='\e[4m'
BOLD='\e[1m'
ITALICS='\e[3m'
RED='\e[31;1m'
GREEN='\e[32;1m'
YELLOW='\e[33;1m'
BLUE='\e[34;1m'
MAGENTA='\e[35;1m'
CYAN='\e[36;1m'
WHITE='\e[37;1m'
END='\e[0m'

# tags
green_tag(){
	echo -e "${GREEN}$1:${END} $2"
}
red_tag(){
	echo -e "${RED}$1:${END} $2"
}

# main function for monitoring
monitor() 
{
	# clear the screen
	clear
	if [[ $# -eq 0 ]]; then 
		# Check if connected to Internet or not
		ping -c 1 google.com &> /dev/null && green_tag Internet Connected || red_tag Internet Disconnected
		# Check OS Type
		green_tag "Operating System Type" "`uname -o`"
		# Check OS Release Version and Name
		green_tag "OS Name" "`cat /etc/os-release | grep VERSION | grep -v VERSION_ID`"
		green_tag "OS Version" "`cat /etc/os-release | grep PRETTY_NAME`"
		# Check Architecture
		green_tag "Architecture" `uname -m`
		# Check Kernel Release
		green_tag "Kernel Release" `uname -r`
		# Check hostname
		green_tag "Hostname" $HOSTNAME
		# Check Internal & external IP and DNS servers
		green_tag "Internal IP" `hostname -I`
		green_tag "External IP" `curl -s ipecho.net/plain;echo`
		green_tag "Name Servers" "`cat /etc/resolv.conf | grep nameserver | cut -d' ' -f2`"
		# Check Logged In Users
		who>/tmp/who
		red_tag "Logged In users" `who`
		# Check RAM and SWAP Usages
		red_tag "Ram Usages" "\n`free -h | grep -v "Swap"`"
		red_tag "Swap Usage" "\n`free -h | grep -v "Mem"`"
		# Check Disk Usages
		green_tag "Disk Usages" "`df -h | grep 'Filesystem\|/dev/sd*' | sed '1d' | cut -d' ' -f1`"
		# Check Load Average
		green_tag "Load Average" "`top -n 1 -b | grep "load average:" | awk '{print $10 $11 $12}'`"
		# Check System Uptime
		green_tag "System Uptime Days/(HH:MM)" "`uptime | awk '{print $3,$4}' | cut -f1 -d,`"
	fi
}

# clean-up function
clean_up()
{
	exit 0;
}

# trap to kill the utility
trap clean_up SIGINT SIGTERM

# main program starts from here
main()
{
	while true; 
	do
		monitor;
		sleep 1;
	done
}

main
exit 0
