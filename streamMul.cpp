#include "ap_axi_sdata.h"
#include "hls_stream.h"

typedef ap_axiu<32, 0, 0, 0> trans_pkt;

void smul(hls::stream< trans_pkt > &INPUT, hls::stream< trans_pkt > &OUTPUT)
{
        #pragma HLS INTERFACE axis port=INPUT
        #pragma HLS INTERFACE axis port=OUTPUT
        trans_pkt data_p;

        INPUT.read(data_p);
        data_p.data *= 2;
        OUTPUT.write(data_p);
}
