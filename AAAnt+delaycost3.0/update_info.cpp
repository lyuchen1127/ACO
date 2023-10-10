#include"main.h"
void UpdatePheromones(double tao[CityCount][CityCount], double Delttao[CityCount][CityCount], solution_Ant ant[AntCount])//更新信息素的函数
{
	for (int i = 0; i < AntCount; i++)
	{
		for (int j = 0; j < CityCount - 1; j++)
		{
			Delttao[ant[i].tour[j]][ant[i].tour[j + 1]] += Q / ant[i].tour_length;
		    Delttao[ant[i].tour[j + 1]][ant[i].tour[j]] += Q / ant[i].tour_length;
		}
		Delttao[ant[i].tour[CityCount - 1]][ant[i].tour[0]] += Q / ant[i].tour_length;
		Delttao[ant[i].tour[0]][ant[i].tour[CityCount - 1]] += Q / ant[i].tour_length;
	}
	for (int i = 0; i < CityCount; i++)
	{
		for (int j = 0; j < CityCount; j++)
		{
			tao[i][j] = (1 -rou) * tao[i][j] + Delttao[i][j];
			Delttao[i][j] = 0;
		}
	}
}

void UpdatePheromones_team(double tao[CityCount][CityCount], double Delttao[CityCount][CityCount], solution_Ant_team ant)//更新团队信息素的函数
{
	for (int i = 0; i <= CarCount; i++)
	{
		if (ant.ant_team[i].tour_length > 0.0)
		{
			//for (int j = 0; j < CityCount - 1; j++)
			for(int j=0;j<ant.ant_team[i].tour_citycount-1;j++)
			{
				Delttao[ant.ant_team[i].tour[j]][ant.ant_team[i].tour[j + 1]] += (Q+1) / (ant.ant_team[i].tour_length+ant.tour_punish[ant.ant_team[i].tour[j + 1]]);
				Delttao[ant.ant_team[i].tour[j + 1]][ant.ant_team[i].tour[j]] += (Q +1)/ (ant.ant_team[i].tour_length+ant.tour_punish[ant.ant_team[i].tour[j]]);
			}
			//Delttao[ant.ant_team[i].tour[CityCount - 1]][ant.ant_team[i].tour[0]] += (Q+1)/ (ant.ant_team[i].tour_length+ant.tour_punish[ant.ant_team[i].tour[0]]);
			//Delttao[ant.ant_team[i].tour[0]][ant.ant_team[i].tour[CityCount - 1]] += (Q +1)/ (ant.ant_team[i].tour_length +ant.tour_punish[ant.ant_team[i].tour[CityCount - 1]]);
		}
	}
	for (int i = 0; i < CityCount; i++)
	{
		for (int j = 0; j < CityCount; j++)
		{
			tao[i][j] = (1 -rou) * tao[i][j] + Delttao[i][j];
			Delttao[i][j] = 0;
		}
	}
}