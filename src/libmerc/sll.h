/*
 * sll.h
 *
 */

#ifndef SLL_H
#define SLL_H

#include "datum.h"

class sll {
public:
    static bool is_ip(datum& pkt) {
        pkt.skip(2);
        uint16_t arp_proto;
        if (!pkt.read_uint16(&arp_proto)) {
            return false;
        }
        if (arp_proto != 1 /* Ethernet */) {
            return false;
        }
        pkt.skip(10);
        uint16_t eth_proto;
        if (!pkt.read_uint16(&eth_proto)) {
            return false;
        }
        return eth_proto == ETH_TYPE_IP || eth_proto == ETH_TYPE_IPV6;
    }
};

#endif  /* SLL_H */
