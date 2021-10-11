#include "Mixed.h"

Mixed::Mixed(int a){
    interger = a;
    denominator = 0;
    numerator = 0;
}

Mixed::Mixed(int a, int b, int c){
    interger = a;
    numerator = b;
    denominator = c;

    if(interger != 0){
        if(numerator < 0 || denominator < 0){
            interger = 0;
            numerator = 0;
            denominator = 0;
        }
    }
    else{  //interger == 0
        if(denominator < 0){
            interger = 0;
            numerator = 0;
            denominator = 0;
        }
        else if(numerator == 0){
            denominator = 0;
        }
    }
}

double  Mixed::Evaluate(){
    double a = (double)this->interger;
    double b = (double)this->numerator;
    double c = (double)this->denominator;
    double sum;
    if(b == 0 && c == 0){
        sum = a;
    }
    else if(a < 0){
        sum = a - b / c;
    }
    else{
        sum = a + b / c;
    }
    return sum;
}

void    Mixed::Simplify(){
    int add_num = 0, m = 0, n = 0, minus_num = 0;
    //cout << "  " << interger << "  " <<numerator << "   " << denominator << endl;
    if(interger != 0 && numerator == 0 && denominator == 0){
        return;
    }
    else if(interger != 0 && numerator == 0 && denominator != 0){
        //cout << "000" << endl;
        denominator = 0;
    }
    else if(interger > 0){
        if(numerator >= denominator){  //int+, num+, den+, 
            add_num = numerator / denominator;
            interger += add_num;
            numerator -= (add_num*denominator);
            if(numerator == 0)
                denominator = 0;
        }
        if(numerator != 0 && denominator != 0){
            m = denominator;
            n = numerator;
            while(n != 0){
                int r = m % n;
                m = n;
                n = r; 
            }
            numerator /= m;
            denominator /= m;
        }
        
    }
    else if(interger < 0){
        if(numerator >= denominator){
            minus_num = numerator / denominator;
            interger -= minus_num;
            numerator -= (minus_num*denominator);
            if(numerator == 0)
                denominator = 0;
        }
        if(numerator != 0 && denominator != 0){
            m = denominator;
            n = numerator;
            while(n != 0){
                int r = m % n;
                m = n;
                n = r; 
            }
            numerator /= m;
            denominator /= m;
        }
    }
    else if(interger == 0){
        if(numerator > 0){
            if(numerator >= denominator){
                interger = numerator / denominator;
                numerator -= (interger * denominator);
                if(numerator == 0)
                    denominator = 0;
            }
            if(numerator != 0 && denominator != 0){
                m = denominator;
                n = numerator;
                while(n != 0){
                    int r = m % n;
                    m = n;
                    n = r; 
                }
                numerator /= m;
                denominator /= m;
            }
        }
        else if(numerator < 0){
            if(-(numerator) > denominator){
                interger = numerator / denominator;
                numerator = -(numerator) + (interger) * denominator;
                if(numerator == 0)
                    denominator = 0;
            }
            if(interger != 0){
                m = denominator;
                n = numerator;
                while(n != 0){
                    int r = m % n;
                    m = n;
                    n = r;
                }
                denominator /= m;
                numerator /= m;
            }
            else{
                m = denominator;
                n = -(numerator);
                while(n != 0){
                    int r = m % n;
                    m = n;
                    n = r;
                }
                denominator /= m;
                numerator /= m;
            }
            
        }
        else{
            //cout << "111" << endl;
            denominator = 0;
            //cout << "222" << endl;
        }
    }
}

void    Mixed::ToFraction(){
    this->Simplify();
    if(this->interger != 0 && this->numerator == 0 && this->denominator == 0){
        this->denominator = 1;
        this->numerator = this->interger;
        this->interger = 0;
    }
    if(this->interger > 0){
        this->numerator += this->interger * this->denominator;
        this->interger = 0; 
    }
    else if(this->interger < 0){
        this->numerator += -(this->interger) * this->denominator;
        this->numerator = -(this->numerator);
        this->interger = 0;
    }
}


bool    Mixed::operator<(const Mixed &m){
    double  val = this->Evaluate();
    Mixed   tmp = m;
    double  val2 = tmp.Evaluate();
    if(val > val2)
        return false;
    else return true;
}

bool    Mixed::operator>(const Mixed &m){
    double  val = this->Evaluate();
    Mixed   tmp = m;
    double  val2 = tmp.Evaluate();
    if(val < val2)
        return false;
    else    return true;
}

bool    Mixed::operator<=(const Mixed &m){
    double  val = this->Evaluate();
    Mixed   tmp = m;
    double  val2 = tmp.Evaluate();
    if(val <= val2)
        return true;
    else    return false;
}

bool    Mixed::operator>=(const Mixed &m){
    double  val = this->Evaluate();
    Mixed   tmp = m;
    double  val2 = tmp.Evaluate();
    if(val >= val2)
        return true;
    else    return false;
}

bool    Mixed::operator==(const Mixed &m){
    Mixed   tmp2 = (*this);
    tmp2.Simplify();
    Mixed   tmp = m;
    tmp.Simplify();
    if(tmp2.interger == tmp.interger && tmp2.numerator == tmp.numerator && tmp2.denominator == tmp.denominator)
        return true;
    else    return false;

}

bool    Mixed::operator!=(const Mixed &m){
    Mixed   tmp2 =(*this);
    tmp2.Simplify();
    Mixed   tmp = m;
    tmp.Simplify();
    if(tmp2.interger == tmp.interger && tmp2.numerator == tmp.numerator && tmp2.denominator == tmp.denominator)
        return false;
    else    return true;
}

Mixed   Mixed::operator+(const Mixed &m){
    Mixed   sum, tmp = m;
    
    if(tmp.numerator == 0  && this->numerator == 0 ){
        sum.interger = tmp.interger + this->interger;
        sum.numerator = 0;
        sum.denominator = 0;
    }
    
    else if(tmp.interger == 0 && tmp.numerator == 0 && tmp.denominator == 0){  //tmp == 0 
        Mixed   tmp2 = (*this);
        sum.interger = tmp2.interger;
        sum.numerator = tmp2.numerator;
        sum.denominator = tmp2.denominator;
    }
    else if(this->interger == 0 && this->numerator == 0 && this->denominator == 0){
        //tmp.ToFraction();
        sum.interger = tmp.interger;
        sum.numerator = tmp.numerator;
        sum.denominator = tmp.denominator;
    }
    else{
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        tmp.ToFraction();
        sum.interger = 0;
        sum.numerator = tmp2.numerator * tmp.denominator + tmp.numerator * tmp2.denominator;
        sum.denominator = tmp2.denominator * tmp.denominator;
    }
    sum.Simplify();
    return sum;
}

Mixed   Mixed::operator-(const Mixed &m){
    Mixed   sum, tmp = m;
    //cout << "+this: " << this->interger << " " << this->numerator << " " << this->denominator << endl;
    //cout << "+m: " << tmp.interger << " " << tmp.numerator << " " << tmp.denominator << endl;
    
    if(tmp.numerator == 0 && this->numerator == 0){
        sum.interger =  this->interger - tmp.interger;
        sum.numerator = 0;
        sum.denominator = 0;
    }
    else if(tmp.interger == 0 && tmp.numerator == 0 && tmp.denominator == 0){  //tmp == 0 
        Mixed   tmp2 = (*this);
        sum.interger = tmp2.interger;
        sum.numerator = tmp2.numerator;
        sum.denominator = tmp2.denominator;
    }
    else if(this->interger == 0 && this->numerator == 0 && this->denominator == 0){
        tmp.ToFraction();
        sum.interger = 0;
        sum.numerator = -(tmp.numerator);
        sum.denominator = tmp.denominator;
    }
    else{
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        tmp.ToFraction();
        //cout << "tmp2: " << tmp2.interger << " " << tmp2.numerator << " " << tmp2.denominator << endl;
        //cout << "+m: " << tmp.interger << " " << tmp.numerator << " " << tmp.denominator << endl;
        sum.interger = 0;
        sum.numerator = tmp2.numerator * tmp.denominator - tmp.numerator * tmp2.denominator;
        sum.denominator = tmp2.denominator * tmp.denominator;
        //cout << "sum: " << sum.interger << " "<< sum.numerator << " " <<sum.denominator << endl;
    }
    sum.Simplify();
    return sum;
}
        
Mixed   Mixed::operator*(const Mixed &m){
    Mixed   sum, tmp = m;

    if(tmp.numerator == 0 && this->numerator == 0){
        sum.interger = tmp.interger * this->interger;
        sum.numerator = 0;
        sum.denominator = 0;
    }
    else if(tmp.numerator == 0){
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        sum.interger = 0;
        sum.numerator = tmp2.numerator * tmp.interger;
        sum.denominator = tmp2.denominator;
    }
    else if(this->numerator == 0){
        tmp.ToFraction();
        sum.interger = 0;
        sum.numerator = tmp.numerator * this->interger;
        sum.denominator = tmp.denominator;
    }
    else{
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        tmp.ToFraction();
        sum.interger = 0;
        sum.numerator = tmp2.numerator * tmp.numerator;
        sum.denominator = tmp2.denominator * tmp.denominator;
    }
    sum.Simplify();
    return sum;
}
        
Mixed   Mixed::operator/(const Mixed &m){  //do not consider the '/0'
    Mixed   sum, tmp = m;
    if(tmp.interger == 0 && tmp.numerator == 0){  //not legal  m == 0
        sum.interger = 0;
        sum.numerator = 0;
        sum.denominator = 0;
    }
    else if(tmp.numerator == 0 && this->numerator == 0){  //this is int and m is int
        sum.interger = 0;
        if(tmp.interger < 0){
            sum.numerator = -(this->interger);
            sum.denominator = -(tmp.interger);
        }
        else{
            sum.numerator = this->interger;
            sum.denominator = tmp.interger;
        }
    }
    else if(tmp.numerator == 0){ //m is int
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        sum.interger = 0;
        if(tmp.interger < 0){
            sum.numerator = -(tmp2.numerator) ;
            sum.denominator = tmp2.denominator * -(tmp.interger);
        }
        else{
            sum.numerator = tmp2.numerator ;
            sum.denominator = tmp2.denominator * tmp.interger;
        }
    }
    else if(this->numerator == 0){  //this is int or 0
        tmp.ToFraction();
        sum.interger = 0;
        if(tmp.numerator < 0){
            sum.numerator = this->interger * -(tmp.denominator) ;
            sum.denominator = -(tmp.numerator);
        }
        else{
            sum.numerator = this->interger * tmp.denominator ;
            sum.denominator = tmp.numerator;
        }
    }
    else{
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        tmp.ToFraction();
        sum.interger = 0;
        if(tmp.numerator >= 0){
            sum.numerator = tmp2.numerator * tmp.denominator;
            sum.denominator = tmp2.denominator * tmp.numerator;
        }
        else{
            //cout << "this: "<< tmp2.numerator << " " <<tmp2.denominator << endl;
            //cout << "tmp: "<< tmp.numerator << " " <<tmp.denominator << endl;
            sum.numerator = tmp2.numerator * -(tmp.denominator);
            sum.denominator = tmp2.denominator * -(tmp.numerator);
            //cout << "sum: "<< sum.numerator << " " << sum.denominator << endl;
        }
    }
    sum.Simplify();
    //cout << "sum: "<<sum.interger << " " << sum.numerator << " " << sum.denominator << endl;
    return sum;
}

void   Mixed::operator=(const Mixed &m){
    Mixed   tmp = m;
    this->interger = tmp.interger;
    this->numerator = tmp.numerator;
    this->denominator = tmp.denominator;

} 

Mixed  Mixed::operator!(){
    this->interger = 0;
    this->numerator = 0;
    this->denominator = 0;
    return (*this);
}

Mixed    Mixed::operator+=(const Mixed &m){
    Mixed   sum, tmp = m;
    
    if(tmp.numerator == 0  && this->numerator == 0 ){
        sum.interger = tmp.interger + this->interger;
        sum.numerator = 0;
        sum.denominator = 0;
    }
    
    else if(tmp.interger == 0 && tmp.numerator == 0 && tmp.denominator == 0){  //tmp == 0 
        Mixed   tmp2 = (*this);
        sum.interger = tmp2.interger;
        sum.numerator = tmp2.numerator;
        sum.denominator = tmp2.denominator;
    }
    else if(this->interger == 0 && this->numerator == 0 && this->denominator == 0){
        //tmp.ToFraction();
        sum.interger = tmp.interger;
        sum.numerator = tmp.numerator;
        sum.denominator = tmp.denominator;
    }
    else{
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        tmp.ToFraction();
        sum.interger = 0;
        sum.numerator = tmp2.numerator * tmp.denominator + tmp.numerator * tmp2.denominator;
        sum.denominator = tmp2.denominator * tmp.denominator;
    }
    sum.Simplify();
    this->interger = sum.interger;
    this->numerator = sum.numerator;
    this->denominator = sum.denominator;
    return (*this);
}

Mixed    Mixed::operator-=(const Mixed &m){
    Mixed   sum, tmp = m;
    //cout << "+this: " << this->interger << " " << this->numerator << " " << this->denominator << endl;
    //cout << "+m: " << tmp.interger << " " << tmp.numerator << " " << tmp.denominator << endl;
    
    if(tmp.numerator == 0 && this->numerator == 0){
        sum.interger =  this->interger - tmp.interger;
        sum.numerator = 0;
        sum.denominator = 0;
    }
    else if(tmp.interger == 0 && tmp.numerator == 0 && tmp.denominator == 0){  //tmp == 0 
        Mixed   tmp2 = (*this);
        sum.interger = tmp2.interger;
        sum.numerator = tmp2.numerator;
        sum.denominator = tmp2.denominator;
    }
    else if(this->interger == 0 && this->numerator == 0 && this->denominator == 0){
        tmp.ToFraction();
        sum.interger = 0;
        sum.numerator = -(tmp.numerator);
        sum.denominator = tmp.denominator;
    }
    else{
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        tmp.ToFraction();
        //cout << "tmp2: " << tmp2.interger << " " << tmp2.numerator << " " << tmp2.denominator << endl;
        //cout << "+m: " << tmp.interger << " " << tmp.numerator << " " << tmp.denominator << endl;
        sum.interger = 0;
        sum.numerator = tmp2.numerator * tmp.denominator - tmp.numerator * tmp2.denominator;
        sum.denominator = tmp2.denominator * tmp.denominator;
        //cout << "sum: " << sum.interger << " "<< sum.numerator << " " <<sum.denominator << endl;
    }
    sum.Simplify();
    this->interger = sum.interger;
    this->numerator = sum.numerator;
    this->denominator = sum.denominator;
    return (*this);
}

Mixed    Mixed::operator*=(const Mixed &m){
    Mixed   sum, tmp = m;

    if(tmp.numerator == 0 && this->numerator == 0){
        sum.interger = tmp.interger * this->interger;
        sum.numerator = 0;
        sum.denominator = 0;
    }
    else if(tmp.numerator == 0){
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        sum.interger = 0;
        sum.numerator = tmp2.numerator * tmp.interger;
        sum.denominator = tmp2.denominator;
    }
    else if(this->numerator == 0){
        tmp.ToFraction();
        sum.interger = 0;
        sum.numerator = tmp.numerator * this->interger;
        sum.denominator = tmp.denominator;
    }
    else{
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        tmp.ToFraction();
        sum.interger = 0;
        sum.numerator = tmp2.numerator * tmp.numerator;
        sum.denominator = tmp2.denominator * tmp.denominator;
    }
    sum.Simplify();
    this->interger = sum.interger;
    this->numerator = sum.numerator;
    this->denominator = sum.denominator;
    return (*this);
}

Mixed    Mixed::operator/=(const Mixed &m){
    Mixed   sum, tmp = m;
    if(tmp.interger == 0 && tmp.numerator == 0){  //not legal  m == 0
        sum.interger = 0;
        sum.numerator = 0;
        sum.denominator = 0;
    }
    else if(tmp.numerator == 0 && this->numerator == 0){  //this is int and m is int
        sum.interger = 0;
        if(tmp.interger < 0){
            sum.numerator = -(this->interger);
            sum.denominator = -(tmp.interger);
        }
        else{
            sum.numerator = this->interger;
            sum.denominator = tmp.interger;
        }
    }
    else if(tmp.numerator == 0){ //m is int
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        sum.interger = 0;
        if(tmp.interger < 0){
            sum.numerator = -(tmp2.numerator) ;
            sum.denominator = tmp2.denominator * -(tmp.interger);
        }
        else{
            sum.numerator = tmp2.numerator ;
            sum.denominator = tmp2.denominator * tmp.interger;
        }
    }
    else if(this->numerator == 0){  //this is int or 0
        tmp.ToFraction();
        sum.interger = 0;
        if(tmp.numerator < 0){
            sum.numerator = this->interger * -(tmp.denominator) ;
            sum.denominator = -(tmp.numerator);
        }
        else{
            sum.numerator = this->interger * tmp.denominator ;
            sum.denominator = tmp.numerator;
        }
    }
    else{
        Mixed   tmp2 = (*this);
        tmp2.ToFraction();
        tmp.ToFraction();
        sum.interger = 0;
        if(tmp.numerator >= 0){
            sum.numerator = tmp2.numerator * tmp.denominator;
            sum.denominator = tmp2.denominator * tmp.numerator;
        }
        else{
            //cout << "this: "<< tmp2.numerator << " " <<tmp2.denominator << endl;
            //cout << "tmp: "<< tmp.numerator << " " <<tmp.denominator << endl;
            sum.numerator = tmp2.numerator * -(tmp.denominator);
            sum.denominator = tmp2.denominator * -(tmp.numerator);
            //cout << "sum: "<< sum.numerator << " " << sum.denominator << endl;
        }
    }
    sum.Simplify();
    this->interger = sum.interger;
    this->numerator = sum.numerator;
    this->denominator = sum.denominator;
    return (*this);
}

Mixed &   Mixed::operator-(){
    if(this->interger == 0 && this->numerator == 0){  //this is 0
        return (*this);
    }
    else if(this->interger == 0 ){  
        this->numerator = -(this->numerator);
    }
    else {
        this->interger = -(this->interger);
    }
    return (*this);
}

Mixed & Mixed::operator++(){ //++x
    if(this->interger != 0){
        this->interger ++;
    }
    else if(this->interger == 0){
        if(this->numerator >= 0){
            this->interger++;
        }
        else{
            this->numerator += this->denominator;
        }
    }
    return (*this);
}
        
const Mixed Mixed::operator++(int){  //x++
    const Mixed   m = (*this);
    if(this->interger != 0){
        this->interger ++;
    }
    else if(this->interger == 0){
        if(this->numerator >= 0){
            this->interger++;
        }
        else{
            this->numerator += this->denominator;
        }
    }
    return m;
}
        
Mixed & Mixed::operator--(){
    if(this->interger != 0){
        this->interger --;
    }
    else if(this->interger == 0){
        this->numerator -= denominator;
    }
    return (*this);
}
      
const Mixed Mixed::operator--(int){
    const Mixed   m = (*this);
    if(this->interger != 0){
        this->interger --;
    }
    else if(this->interger == 0){
        this->numerator -= denominator;
    }
    return m;
}

istream & operator>>(istream &inp, Mixed &m){
    char c;
    int     num1, num2, num3;
   
    inp >> num1;
    if(inp.get() == '\n'){
        m.interger = num1;
        m.numerator = 0;
        m.denominator = 0;
    }
    else{
        inp >> num2 >> c >> num3;
        if(num2 == 0 && num3 == 0){
            m.interger = 0;
            m.numerator = 0;
            m.denominator = 0;
        }
        else{
            m.interger = num1;
            m.numerator = num2;
            m.denominator = num3;
        }
    }

    return inp;
}

ostream & operator<<(ostream &out, const Mixed &m){
    char c = '/';
    
        if(m.interger != 0){
            if(m.denominator == 0 && m.numerator == 0){
                out << m.interger ;
            }
            else{
                out << m.interger << " " << m.numerator << c << m.denominator;
            }
        }   
        else if(m.interger == 0 && m.numerator == 0 && m.denominator == 0){
            //cout << "111" << endl;
            out << m.interger;
        }
        else
            out << m.numerator << c << m.denominator;
    
    
    return out;
}