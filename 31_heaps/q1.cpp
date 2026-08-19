#include <bits/stdc++.h>
using namespace std;

// max heap - heap

class MonoTonicStack{
    stack<pair<int,int>>in,out;
public:
    MonoTonicStack(){

    }

    void insert(int x){
        if(in.size()==0){
            if(out.size()==0)in.push({x,x});
            else in.push({x,max(x,out.top().second)});
            return;
        }
        in.push({x,max(x,in.top().second)});
    }

    int removeMax(){
        if(in.empty() && out.empty())return -1;
        
        int mxElement = getMax();
        bool flag = false;

        while(!out.empty()){
            int element = out.top().first;
            if(element==mxElement){
                out.pop();
                flag=true;
                break;
            }else{
                if(in.size()==0){
                    in.push({element,element});
                }else{
                    in.push({element,max(element,in.top().second)});
                }
                out.pop();
            }
        }
        if(flag)return mxElement;

        while(!in.empty()){
            int element = in.top().first;
            if(element==mxElement){
                in.pop();
                break;
            }else{
                if(out.size()==0){
                    out.push({element,element});
                }else{
                    out.push({element,max(element,out.top().second)});
                }
                in.pop();
            }
        }
        return mxElement;

    }
    int getMax(){
        if(in.empty())return out.top().second;
        if(out.empty())return in.top().second;
        return max(in.top().second,out.top().second);
    }
    int size(){
        return in.size()+out.size();
    }

};


int main() {
   
    MonoTonicStack st;

    st.insert(4);
    st.insert(6);
    st.insert(2);
    st.insert(23);
    st.insert(12);
    st.insert(-2);
    cout << st.getMax() << endl;
    cout << st.size() << endl;

    cout << st.removeMax() << endl;
    cout << st.removeMax() << endl;
    cout << st.getMax() << endl;
    cout << st.size() << endl;
    cout << st.removeMax() << endl;
    cout << st.getMax() << endl;
    cout << st.removeMax() << endl;
    cout << st.getMax() << endl;
    cout << st.size() << endl;
    cout << st.removeMax() << endl;
    cout << st.size() << endl;
    cout << st.getMax() << endl;
    st.insert(4);
    st.insert(6);
    cout << st.getMax() << endl;

    return 0;
}