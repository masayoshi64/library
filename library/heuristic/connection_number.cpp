/**
 * @brief 連結数: 周囲9マスのうち値がcであるような連結成分の数．1なら連結
 */

ll connection_number(mat<ll>& grid, ll x, ll y, ll c){
    ll h = grid.size();
    ll w = grid[0].size();
    vl val;
    rep(nx, x - 1, x + 2){
        rep(ny, y - 1, y + 2){
            if(nx < 0 || nx >= h || ny < 0 || ny >= w || grid[nx][ny] != c){
                val.pb(0);
            }else{
                val.pb(1);
            }
        }
    }
    ll res = val[1] + val[3] + val[5] + val[7] 
            - val[0] * val[1] * val[3]
            - val[1] * val[2] * val[5]
            - val[3] * val[6] * val[7]
            - val[5] * val[7] * val[8];
    return res;
}