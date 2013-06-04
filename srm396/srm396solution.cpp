
class VerifyCreditCard 
{ 
 public: 
 int calsum(vector <int> v) 
 { 
  int s=0; 
  for(int i=0;i<v.size();i++) 
  { 
   if(v[i]<=9) 
   s+=v[i]; 
   else 
   { 
    s+=v[i]%10; 
    s+=v[i]/10; 
    } 
   } 
  return s; 
  }  
 string checkDigits(string s) 
 { 
  vector <int> v(s.size()+1,0); 
  for(int i=1;i<=s.size();i++) 
  v[i]=s[i-1]-'0'; 
  if(s.size()%2==0) 
  { 
   for(int i=1;i<=s.size();i+=2) 
   v[i]=v[i]*2; 
   } 
  else 
  { 
   for(int i=2;i<=s.size();i+=2) 
   v[i]=v[i]*2; 
   } 
  if(calsum(v)%10==0) 
  return "VALID"; 
  return "INVALID"; 
  } 
 };

// *****************************************************************************
// DNAString
#define SZ(X) ((int)(X.size())) 
#define LN(X) ((int)(X.length())) 
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;} 

class DNAString 
{ 
public: 
  int ID(char c) 
  { 
    if (c=='A') return 0; 
    if (c=='C') return 1; 
    if (c=='G') return 2; 
    return 3; 
  } 
  int minChanges(int m, vector <string> vs) 
  { 
    string str=""; 
    for (int i=0;i<SZ(vs);i++) str+=vs[i]; 
    int n=LN(str); 
    int result=100000000; 
    for (int p=1;p<=m;p++) 
    { 
      int total=0; 
      for (int s=0;s<p;s++) 
      { 
        int C[4]; 
        C[0]=C[1]=C[2]=C[3]=0; 
        for (int i=s;i<n;i+=p) 
          C[ID(str[i])]++; 
        total+=(C[0]+C[1]+C[2]+C[3])-max(max(C[0],C[1]),max(C[2],C[3])); 
      } 
      checkmin(result,total); 
    } 
    return result; 
  } 
};

//
using namespace std;
 
class DNAString {
public:
  int minChanges(int, vector <string>);
};
 
 
// xjtuhyh's 
/*  i 周期一个个的试
 *     j 周期内每个位置要变的次数
 *        k 统计第j个位置，各字母出现的次数
 */
int DNAString::minChanges(int maxPeriod, vector <string> dna) {
    int n = 0;
    string s;
 
    for (int i = 0; i < dna.size(); i++) {
         n = n + dna[i].length();
         s = s + dna[i];
    }
        int ans = n;
    int maxl = maxPeriod;
    
    for (int i = 1; i <= maxl; i++) {
        int now = 0;
        for (int j = 0; j < i; j++) {
            int sum[4];
            memset(sum, 0, sizeof(sum));
            int k = j;
            while (k < n) { 
                  if (s[k] == 'A') sum[0]++;
                  if (s[k] == 'T') sum[1]++;
                  if (s[k] == 'C') sum[2]++;
                  if (s[k] == 'G') sum[3]++;
                  k = k + i;
            }
            int maxk = 0;
            maxk = max(sum[0], sum[1]); maxk = max(maxk, sum[2]);
            maxk = max(maxk, sum[3]);
            now = now + sum[0] + sum[1] + sum[2] + sum[3] - maxk;
        }      
        ans = min(now, ans);
    }
    return ans;
}

// *****************************************************************************
// RemovingDigits

// maksay's 
/* a记录的是digits上各数字出现的次数
*/
int a[10]; 
string n; 
inline bool e() 
{ 
  return (!a[1]&&!a[2]&&!a[3]&&!a[4]&&!a[5]&&!a[6]&&!a[7]&&!a[8]&&!a[9]); 
} 
inline int ok(int x) 
{ 
  int b[10]; 
  int i; 
  for(i=0;i<10;i++) 
    b[i]=0; 
  for(i=0;i<sz(n);i++) 
    if ((int)(n[i]-'0')==x) 
      b[0]++; 
  if (b[0]==a[x]) 
    return -1; 
  for(i=0;i<sz(n)&&(int)(n[i]-'0')!=x;i++) 
    b[(int)(n[i]-'0')]++; 
  if (i==sz(n)) 
    return -1; 
  for(int j=1;j<10;j++) 
    if (b[j]>a[j]) 
      return -1; 
  return i; 

} 
class RemovingDigits 
        { 
        public: 
        string maxNumber(string number, string digits) 
            { 
       n=number; 
       for(int i=0;i<10;i++) 
         a[i]=0; 
       for(int i=0;i<sz(digits);i++) 
         a[(int)(digits[i]-'0')]++; 
       string rez=""; 
       if (sz(digits)==sz(n)) 
         return ""; 
       while(!e()) 
       { 
         int j=-1,i; 
         for(i=9;j==-1&&i>0;i--) 
           j=ok(i); 
         if (!i&&j==-1) 
           return rez; 
         for(int i=0;i<j;i++) 
          a[(int)(n[i]-'0')]--; 
         rez+=n[j]; 
         for(int i=0;i<=j;i++) 
           n.erase(0,1); 
       } 
       return rez+n; 
            } 
         

        }; 

class RemovingDigits {
public:
  string maxNumber(string, string);
};
 
  int a[51], p[51];
    int s[10];
  int v[51];
  int n, m;
  
int cmp(const int & i, const int & j)
{
    if (a[i] > a[j]) return 1;
    if (a[i] < a[j]) return 0;
    if (i < j) return 1;
    return 0;
}
 
int check(int pos, int last)
{
    int ss[10];
    for (int i = 1; i <= 9; i++) ss[i] = s[i];
    for (int i = last + 1; i < pos; i++) if (v[i] == 0) {
        ss[a[i]]--;
        if (ss[a[i]] < 0) return 0;
    }
    
    for (int i = pos + 1; i <= n; i++) ss[a[i]]--;
    for (int i = 1; i <= 9; i++) if (ss[i] > 0) return 0;
    return 1;
}
 
string RemovingDigits::maxNumber(string number, string digits) {
 
  
 
  string ans;
  
  memset(s, 0, sizeof(s));
  for (int i = 0; i < digits.length(); i++) s[digits[i] - '0']++;
  
  
  n = number.size(), m = digits.length();
  for (int i = 0; i < number.size(); i++) a[i + 1] = number[i] - '0';
  
  for (int i = 1; i <= n; i++) p[i] = i;
  sort(p + 1, p + n + 1, cmp);
  
  int pos = 0;
  memset(v, 0, sizeof(v));
  for (int i = 1; i <= n - m; i++) {
      int j;
        for (j = 1; j <= n; j++) 
          if ((p[j] > pos) && (check(p[j], pos))) break;
        
     
        for (int i = pos + 1; i < p[j]; i++) if (v[i] == 0) {
            v[i] = 1;
            s[a[i]]--;
        }
        
        pos = p[j];
        ans = ans + (char)(a[pos] + '0');
    }
    
    return ans;
}


// *****************************************************************************
// FixImage 
using namespace std; 

#define forn(i, n) for (int i = 0; i < (int)(n); i++) 
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++) 
#define sz(a) (int)(a).size() 
#define all(a) (a).begin(), (a).end() 
#define pb push_back 

typedef long long ll; 
typedef vector <int> vi; 

#define maxn 53 
#define inf (int)1e9 

int h, w, u[maxn][maxn]; 
int xmi[maxn], xma[maxn], ymi[maxn], yma[maxn]; 

int cor( int x, int y ) 
{ 
  return 0 <= x && x < w && 0 <= y && y < h; 
} 

vector <string> m; 

void dfs( int x, int y ) 
{ 
  if (!cor(x, y) || u[y][x] || m[y][x] != '#') 
    return; 
  u[y][x] = 1; 
  xmi[y] <?= x, xma[y] >?= x; 
  ymi[x] <?= y, yma[x] >?= y; 
  dfs(x + 1, y); 
  dfs(x - 1, y); 
  dfs(x, y + 1); 
  dfs(x, y - 1); 
} 

class FixImage 
{ 
public: 
  vector <string> originalImage(vector <string> _m) 
  { 
    m = _m, h = sz(m), w = sz(m[0]); 

    int run = 1; 
    while (run) 
    { 
    run = 0;     
    memset(u, 0, sizeof(u)); 
    forn(i, h) 
      forn(j, w) 
        if (!u[i][j] && m[i][j] == '#') 
        { 
          forn(k, h) xmi[k] = inf, xma[k] = -inf; 
          forn(k, w) ymi[k] = inf, yma[k] = -inf; 
          dfs(j, i); 
          forn(k, h) 
            for (int x = xmi[k]; x <= xma[k]; x++) 
            { 
              if (m[k][x] != '#') 
                run = 1; 
              m[k][x] = '#', u[k][x] = 1; 
            } 
          forn(k, w) 
            for (int y = ymi[k]; y <= yma[k]; y++) 
            { 
              if (m[y][k] != '#') 
                run = 1; 
              m[y][k] = '#', u[y][k] = 1; 
            } 
        } 
    } 
    return m; 
  } 
};

// *****************************************************************************
// MoreNim 
// ACRush
using namespace std; 

#define SZ(X) ((int)(X.size())) 
typedef long long int64; 
template<class T> inline T lowbit(T n){return (n^(n-1))&n;} 
int64 toInt64(string s){int64 r=0;istringstream sin(s);sin>>r;return r;} 

class MoreNim 
{ 
public: 
  int64 bestSet(vector <string> heaps) 
  { 
    int n=SZ(heaps); 
    int64 A[60],B[60]; 
    for (int i=0;i<n;i++) A[i]=toInt64(heaps[i]); 
    sort(A,A+n); 
    reverse(A,A+n); 
    for (int i=0;i<n;i++) B[i]=A[i]; 
    int64 result=0; 
    for (int i=0;i<n;i++) 
    { 
      int64 set=A[i]; 
      if (set==0)  
      { 
        result+=B[i]; 
        continue; 
      } 
      int64 key=lowbit(set); 
      for (int j=i+1;j<n;j++) 
        if (A[j]&key) 
          A[j]^=set; 
    } 
    return result; 
  } 
};
//  ilyaraz
using namespace std; 

int mt[100][100]; 

struct MoreNim 
{ 
  bool cool(vector<long long> &a) 
  { 
    for (int i = 0; i < a.size(); i++) 
    { 
      for (int j = 0; j < 55; j++) 
      { 
        mt[j][i] = (a[i] >> j) & 1; 
      } 
    } 
    int n = a.size(); 
    for (int i = 0; i < n; i++) 
    { 
      int r = -1; 
      for (int j = i; j < 55; j++) 
      { 
        if (mt[j][i]) 
        { 
          r = j; 
          break; 
        } 
      } 
      if (r == -1) return false; 
      for (int j = 0; j < n; j++) 
        swap(mt[r][j], mt[i][j]); 
      for (int j = i + 1; j < 55; j++) 
      { 
        if (!mt[j][i]) continue; 
        for (int k = 0; k < n; k++) 
          mt[j][k] ^= mt[i][k]; 
      } 
    } 
    return true; 
  } 
  long long bestSet(vector <string> heaps) 
  { 
    vector<long long> a(heaps.size()); 
    for (int i = 0; i < heaps.size(); i++) 
    { 
      stringstream ss(heaps[i]); 
      ss >> a[i]; 
    } 
    sort(a.begin(), a.end(), greater<long long>()); 
    vector<long long> opt; 
    for (int i = 0; i < a.size(); i++) 
    { 
      opt.push_back(a[i]); 
      if (!cool(opt)) opt.pop_back(); 
    } 
    long long sum = 0; 
    for (int i = 0; i < a.size(); i++) 
      sum += a[i]; 
    for (int i = 0; i < opt.size(); i++) 
      sum -= opt[i]; 
    return sum; 
  } 
};
