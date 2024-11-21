#!/bin/bash

gather_info() {
    echo "------------------------------------"
    echo "Architecture: $(uname -a)"
    echo "Physical CPUs: $(grep -c '^physical id' /proc/cpuinfo)"
    echo "Virtual CPUs: $(grep -c '^processor' /proc/cpuinfo)"
    RAM_TOTAL=$(free -m | awk '/^Mem:/{print $2}')
    RAM_USED=$(free -m | awk '/^Mem:/{print $3}')
    RAM_USAGE=$(awk "BEGIN {printf \"%.2f\", ($RAM_USED/$RAM_TOTAL)*100}")
    echo "RAM Usage: $RAM_USED MB / $RAM_TOTAL MB (${RAM_USAGE}%)"
    DISK_TOTAL=$(df -h --total | awk '/^total/{print $2}')
    DISK_USED=$(df -h --total | awk '/^total/{print $3}')
    DISK_USAGE=$(df -h --total | awk '/^total/{print $5}')
    echo "Disk Usage: $DISK_USED / $DISK_TOTAL (${DISK_USAGE})"
    CPU_USAGE=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')
    echo "CPU Usage: ${CPU_USAGE}%"
    LAST_REBOOT=$(who -b | awk '{print $3, $4}')
    echo "Last Reboot: $LAST_REBOOT"
    LVM_STATUS=$(lsblk | grep -q 'lvm' && echo "Active" || echo "Inactive")
    echo "LVM Status: $LVM_STATUS"
    ACTIVE_CONNECTIONS=$(ss -tun | grep -c ESTAB)
    echo "Active Connections: $ACTIVE_CONNECTIONS"
    USERS=$(who | wc -l)
    echo "Number of Users: $USERS"
    IPV4=$(ip a | awk '/inet / && !/127.0.0.1/{print $2}' | cut -d'/' -f1)
    MAC=$(ip link show | awk '/ether/{print $2}')
    echo "IPv4 Address: $IPV4"
    echo "MAC Address: $MAC"
    SUDO_CMDS=$(grep -c 'COMMAND=' /var/log/sudo/sudo.log 2>/dev/null || echo 0)
    echo "Sudo Commands Executed: $SUDO_CMDS"
    echo "------------------------------------"
}
gather_info | wall
