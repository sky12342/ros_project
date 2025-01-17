#include"destinatoinSiteBuffer.h"
std::queue<std::pair<int, int>> DestinationSiteBuffer::site_buffer_;
using namespace std;

    void DestinationSiteBuffer::push(int x ,int y){
     if(site_buffer_.size()< MAX_SITE_LENTH ){
        site_buffer_.emplace(make_pair(x,y));
     }
    }
    void DestinationSiteBuffer::swap(std::queue<std::pair<int,int>> &tmp){
        site_buffer_.swap(tmp);
    }


