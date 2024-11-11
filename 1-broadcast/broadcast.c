#include "base.h"
#include <stdio.h>

extern ustack_t *instance;

// the memory of ``packet'' will be free'd in handle_packet().
void broadcast_packet(iface_info_t *iface, const char *packet, int len)
{
	iface_info_t *tx_iface = NULL;
	list_for_each_entry(tx_iface, &instance->iface_list, list) {
		if (tx_iface->index != iface->index)
			iface_send_packet(tx_iface, packet, len);
	}
	// TODO: broadcast packet 
	fprintf(stdout, "TODO: broadcast packet.\n");
}
