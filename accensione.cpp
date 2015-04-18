const int MAXN=1000005;

int contaAccensioni;
int multipli[MAXN];

void Accendi(int N, int acceso[], int pulsante[])
{
  for(int i=N; i>0; i--){
    contaAccensioni=0;
    for(int j=2; i*j<=N; j++)
      contaAccensioni+=multipli[i*j];
    if( (acceso[i]==1 && contaAccensioni%2==1) || (acceso[i]==0 && contaAccensioni%2==0) ) multipli[i]=pulsante[i]=1;
  }

  return;
}
