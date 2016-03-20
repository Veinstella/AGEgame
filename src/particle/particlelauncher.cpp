#include "../include/particlelauncher.h"

#include "../include/particle.h"
#include "stdlib.h"
#include <qsettings>
#include "../include/age_system.h"
ParticleLauncher::ParticleLauncher(const char * file_name,int amount)
{
    this->amount=amount;
    QSettings *configIniRead = new QSettings(file_name, QSettings::IniFormat);
    QString texture_string=ASystem::Path(configIniRead->value("/particle/texture").toString().toStdString().c_str());
    //qDebug()<<texture_string;
    begin_angle=configIniRead->value("/particle/begin_angle").toDouble();
    //qDebug()<<"begin angle"<<begin_angle;
    end_angle=configIniRead->value("/particle/end_angle").toDouble();
    //qDebug()<<"end angle"<<end_angle;
    pos_offset_x=configIniRead->value("/particle/pos_offset_x").toInt();
    pos_offset_y=configIniRead->value("/particle/pos_offset_y").toInt();
    pos=AVector2D(
                configIniRead->value("/particle/pos_x").toInt(),
                  configIniRead->value("/particle/pos_y").toInt()
                  );
    //qDebug()<<"pos "<<pos;
    begin_size=AVector2D(
                configIniRead->value("/particle/begin_width").toInt(),configIniRead->value("/particle/begin_height").toInt()
                );
    //qDebug()<<"begin size "<<begin_size;
    end_size=AVector2D(
                configIniRead->value("/particle/end_width").toInt(),configIniRead->value("/particle/end_height").toInt()
                );
    //qDebug()<<"end size "<<end_size;
    begin_color=AColor(
                configIniRead->value("/particle/begin_red").toDouble(),
                configIniRead->value("/particle/begin_green").toDouble(),
                configIniRead->value("/particle/begin_blue").toDouble()
                );
    //qDebug()<<"begin color "<<begin_color.red <<" "<<begin_color.green<<" "<<begin_color.blue;
    end_color=AColor(
                configIniRead->value("/particle/end_red").toDouble(),
                configIniRead->value("/particle/end_green").toDouble(),
                configIniRead->value("/particle/end_blue").toDouble()
                );
    //qDebug()<<"end_color "<<end_color.red <<" "<<end_color.green<<" "<<end_color.blue;
    escape_speed=configIniRead->value("/particle/escape_speed").toDouble();
    //qDebug()<<"escape_speed" <<escape_speed;
    angle_speed=configIniRead->value("/particle/angle_speed").toDouble();
    // qDebug()<<"angle_speed" <<angle_speed;
    span=configIniRead->value("/particle/span").toInt();
    //qDebug()<<"span" <<span;
    begin_alpha=configIniRead->value("/particle/begin_alpha").toFloat();
    end_alpha=configIniRead->value("/particle/end_alpha").toFloat();
    rotate_speed=configIniRead->value("/particle/rotate_speed").toDouble();
    gravity=AVector2D(
                configIniRead->value("/particle/gravity_x").toFloat(),
                configIniRead->value("/particle/gravity_y").toFloat()
                );

    this->texture=new ATexture(texture_string);
}

void ParticleLauncher::fire(AVector2D where,ALayer * layer)
{



    double m=(this->end_angle-this->begin_angle)/this->amount;

    for(int i=0;i<amount;i++)
    {
        AVector2D tmp_pos= AVector2D(where.x()+this->pos.x()+rand()%pos_offset_x,where.y()+this->pos.y());
       layer->addChild(new Particle(this->texture,this->begin_angle+m*i,tmp_pos,this->begin_size,this->end_size,this->begin_color
                                 ,this->end_color,this->escape_speed,this->angle_speed,this->span,this->begin_alpha
                                 ,this->end_alpha,this->rotate_speed,this->gravity));
       /* layer->addChild( new Particle(this->texture,0,
                                      where,
                                      AVector2D(15,15),AVector2D(5,5),
                                      AColor(1,1,1),
                                      AColor(1,0,1),0.01,0,1000,1,1,0,
                                      AVector2D(0,0)));
*/

    }
}
