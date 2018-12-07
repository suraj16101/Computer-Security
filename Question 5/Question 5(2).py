import dpkt
from _socket import inet_ntoa

def main():
    malicious_ip = []
    pcap = dpkt.pcap.Reader(open('log.pcap', 'rb'))  # Reading the file in pcap format

    for ts, buf in pcap:
        eth = dpkt.ethernet.Ethernet(buf)  # Extracting the ethernet files

        if eth.type == dpkt.ethernet.ETH_TYPE_IP:  # Packet IP type
            ip = eth.data
            if ip.p == dpkt.ip.IP_PROTO_TCP:  # Packet TCP type
                tcp = ip.data
                if tcp.flags == 0x2 and inet_ntoa(ip.src) not in malicious_ip:  # Checking for SYN packets
                    malicious_ip.append(inet_ntoa(ip.src))  # Storing distinct malicious IPs in a list

    print (malicious_ip)


main()