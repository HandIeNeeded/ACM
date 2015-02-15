vector<Line> Half_Plane(vector<Line> line)
{
    deque<Line> ql;
    deque<Point> qd;
    vector<Line> Core;

    REP(i, 4)
        line.push_back(Boundary[i]);
    sort(line.begin(), line.end(), cmp);
    //加入边界为了处理交集无界的情况，如果保证有界可以不加

    REP(i, line.size())
    {
        while (qd.size() && onRight(line[i], qd.back()))
            qd.pop_back(), ql.pop_back();

        while (qd.size() && onRight(line[i], qd.front()))
            qd.pop_front(), ql.pop_front();

        if (ql.size() && ql.back().dir == line[i].dir)
        {
            if (onRight(line[i], ql.back().p1))
            {
                ql.pop_back();
                if (qd.size())
                    qd.pop_back();
            } 
            else
                continue;
        }

        if (ql.size() && ql.front().dir == -line[i].dir)
            if (onRight(line[i], ql.front().p1))
                return Core;

        if (ql.size())
            qd.push_back(cross(ql.back(), line[i]));
        ql.push_back(line[i]);

        if (qd.size() > 1 && onRight(ql.front(), qd.back()))
            ql.pop_back(), qd.pop_back();
    }
    if (ql.size() < 3)
        return Core;
    while (ql.size())
    {
        Core.push_back(ql.front());
        ql.pop_front();
    }
    return Core;
}
