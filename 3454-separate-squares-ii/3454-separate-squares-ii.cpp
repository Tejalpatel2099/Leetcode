
class Solution {
public:
    struct Event {
        long long y;
        long long x1, x2;
        int type; // +1 entering, -1 leaving
        bool operator<(Event const& other) const {
            return y < other.y;
        }
    };

    struct SegTree {
        int n; // number of x-segments (xs.size()-1)
        vector<int> cover;
        vector<long long> len;
        vector<long long> *xs;

        SegTree(int n_, vector<long long> &coords) : n(n_) {
            cover.assign(4 * n, 0);
            len.assign(4 * n, 0);
            xs = &coords;
        }

        void pull(int node, int l, int r) { // covers segment indices [l,r)
            if (cover[node] > 0) {
                len[node] = (*xs)[r] - (*xs)[l];
            } else if (r - l == 1) {
                len[node] = 0;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                cover[node] += val;
                pull(node, l, r);
                return;
            }
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid, r, ql, qr, val);
            pull(node, l, r);
        }

        void update(int ql, int qr, int val) {
            if (ql < qr) update(1, 0, n, ql, qr, val);
        }

        long long queryLen() const {
            return len[1];
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        int N = (int)squares.size();
        vector<long long> xs;
        xs.reserve(2 * N);
        vector<Event> ev;
        ev.reserve(2 * N);

        for (auto &sq : squares) {
            long long x = sq[0], y = sq[1], l = sq[2];
            long long x1 = x, x2 = x + l;
            long long y1 = y, y2 = y + l;
            xs.push_back(x1);
            xs.push_back(x2);
            ev.push_back({y1, x1, x2, +1});
            ev.push_back({y2, x1, x2, -1});
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ev.begin(), ev.end());

        int m = (int)xs.size();
        if (m <= 1) return 0.0; // no width at all (practically impossible with l>=1)

        // number of elementary x-intervals
        int segN = m - 1;
        SegTree st(segN, xs);

        // sweep to compute total area and store slabs
        struct Slab { long double y, dy, xlen; };
        vector<Slab> slabs;
        slabs.reserve(ev.size());

        long long prevY = ev[0].y;
        long long xlen = 0;
        long double total = 0.0L;

        int i = 0;
        while (i < (int)ev.size()) {
            long long curY = ev[i].y;
            long long dy = curY - prevY;

            if (dy > 0) {
                long double add = (long double)xlen * (long double)dy;
                total += add;
                slabs.push_back({(long double)prevY, (long double)dy, (long double)xlen});
            }

            // process all events at curY
            while (i < (int)ev.size() && ev[i].y == curY) {
                int l = (int)(lower_bound(xs.begin(), xs.end(), ev[i].x1) - xs.begin());
                int r = (int)(lower_bound(xs.begin(), xs.end(), ev[i].x2) - xs.begin());
                st.update(l, r, ev[i].type);
                i++;
            }

            xlen = st.queryLen();
            prevY = curY;
        }

        long double target = total / 2.0L;
        long double cum = 0.0L;
        const long double EPS = 1e-12L;

        for (auto &sl : slabs) {
            // if we already hit half exactly at this boundary, it's the minimum y
            if (fabsl(cum - target) <= EPS) {
                return (double)sl.y;
            }

            long double slabArea = sl.xlen * sl.dy;

            if (cum + slabArea < target - EPS) {
                cum += slabArea;
                continue;
            }

            // target is within this slab (or at its start/end)
            if (sl.xlen <= 0) {
                // No area here; if we couldn't reach target, continue (shouldn't happen for consistent data)
                continue;
            }

            long double rem = target - cum;           // area needed inside this slab
            long double yAns = sl.y + rem / sl.xlen;  // linear within slab
            return (double)yAns;
        }

        // If target == total, answer is at the very top boundary.
        // Return max y among events.
        return (double)prevY;
    }
};
