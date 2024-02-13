/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_dfs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 03:31:25 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/02/13 20:41:27 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
typedef struct s_step
{
	char			*name;
	int				*int_name;
	struct s_stack	*copt_head_a;
	struct s_step	*next;
}	t_step;
*/

void	push_swap_dfs(t_vars *vars);

void	push_swap_dfs(t_vars *vars)
{
	long	command;


	// 今のターン数が、既存の解答ターン数と同じなら、枝切り。
	// これ以上探索しても短い手じゃないから。
	if (turn >= t->max_turn)
		return ;

	// スタックaが昇順ソートになったら解答。t->max_turn(今の最短手数)を更新する。
	if (flag = 1 and len < maxlen)
		return (ans_update(turn, t));

	// ra, saなど11の操作を数値化したもの。
	command = -1;

	while (++command < 11)
	{
		// たとえば PA -> PB は、手数が増えるだけなので、枝切り。
		if (avoid_check(command, t) || turn >= t->max_turn)
			continue;

		// raとかpbとか、コマンド実行。スタックa, bを変更させちゃう。
		if (change_dlst(a, b, command, true))
			continue;

		// 次の手を見に行く
		dfs(a, b, t, turn + 1);

		// バックトラック法
		// スタックa, bの復元。さっきの反対コマンドを行う。raならrraで復元。
		change_dlst(a, b, command, false);
	}
}
/*
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n; i > (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
using namespace std;

int main()
{
	// 作りかけの数列を格納するqueueを作る
	queue<vector<int>> que;
	// 1~4を格納しておく
	rep(i, 4){
		vector<int> initial = {i+1};
		que.push(initial);
	}

	// スタックが空になるまで繰り返す
	while (!que.empty()){
		// スタックの頭にあるものを取り出す
		vector<int> elem = que.front();

		// 処理した先頭の要素は削除しておく
		que.pop();

		// もし数列の長さが3であれば解答出力
		if (elem.size()==3){
				for (auto x : elem) cout << x;
				cout << endl;
			}

		// まだ数列の長さが3でなければ「前の要素以上の4以下の」要素を付け加える
		else {
			// ここでも1~4を格納しておく
			repi(i, elem[elem.size()-1], 4){
					// 要素を付け加える新しい数列
					vector<int> elem_new = elem;
					// 要素を付け加える
					elem_new.push_back(i);
					// キューに入れる
					que.push(elem_new);
			}
		}
	}
}
*/