# Generated by Django 2.1.1 on 2018-10-27 08:30

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('app', '0032_auto_20181024_0727'),
    ]

    operations = [
        migrations.CreateModel(
            name='PublicKey',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('publickey', models.CharField(max_length=255, unique=True, verbose_name='public key')),
                ('user', models.ForeignKey(on_delete=django.db.models.deletion.CASCADE, related_name='publickey_user', to=settings.AUTH_USER_MODEL)),
            ],
        ),
    ]