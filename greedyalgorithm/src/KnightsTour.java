import java.io.*;
import java.util.*;

//int moves_x[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
//int moves_y[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

public class KnightsTour {
	public static  final int BOARD_SIZE = 8;
	public int [][] board = new int[BOARD_SIZE][BOARD_SIZE];


	public void test(){
		Random rand = new Random();

		for(int i = 0; i < BOARD_SIZE; i++){
			for(int j = 0; i < BOARD_SIZE; i++){
				board[i][j] = 0;
			}	
		}

		int x = rand.nextInt(BOARD_SIZE);
		int y = rand.nextInt(BOARD_SIZE); 
		nextMove(x,y);
	}
	

	public boolean nextMove(int row, int column){
		//mark visited
		board[row][column] = 1;

		ArrayList<Coordinate> possibleNextMoves = possibleMoves(row,column);
		
		if(possibleNextMoves.size() == 0){
			printBoard();
			System.out.println("Tour complete");
		}
		
		else{
				
		Coordinate nextMove = solve(possibleNextMoves);	
		int nextRow = nextMove.getRow();
		int nextColumn = nextMove.getColumn();
		
		printBoard();
		System.out.println();
		System.out.println();
		
		return nextMove(nextRow,nextColumn);
		}
		
		return true;
	}
	
	public ArrayList<Coordinate> possibleMoves(int row, int column){
		
		ArrayList<Coordinate> possibleMoves = new ArrayList<Coordinate>();

		if( isValidMove(new Coordinate(row-2, column -1)) ){
			possibleMoves.add(new Coordinate(row-2, column -1));
		}

		if( isValidMove(new Coordinate(row-2, column +1)) ){
			possibleMoves.add(new Coordinate(row-2, column +1));
		}	

		if( isValidMove(new Coordinate(row-1, column +2)) ){
			possibleMoves.add(new Coordinate(row-1, column +2));
		}	

		if( isValidMove(new Coordinate(row+1, column +2)) ){
			possibleMoves.add(new Coordinate(row+1, column +2));
		}	

		if( isValidMove(new Coordinate(row+2, column +1)) ){
			possibleMoves.add(new Coordinate(row+2, column +1));
		}

		if( isValidMove(new Coordinate(row+2, column-1)) ){
			possibleMoves.add(new Coordinate(row+2, column-1));
		}	

		if( isValidMove(new Coordinate(row+1, column -2)) ){
			possibleMoves.add(new Coordinate(row+1, column -2));
		}	

		if( isValidMove(new Coordinate(row-1, column -2)) ){
			possibleMoves.add(new Coordinate(row-1, column-2));
		}	
		
		return possibleMoves;
	}


	public boolean isValidMove(Coordinate pos){
		
		if(pos.getRow() < 0 || pos.getColumn() < 0){
			return false;
		}
		if(pos.getRow() >= BOARD_SIZE || pos.getColumn() >= BOARD_SIZE){
			return false;
		}
		
		if(board[pos.getRow()][pos.getColumn()] == 1){
			return false;
		}

		return true;
	}
	

	public Coordinate solve(ArrayList<Coordinate> neighbors){
		Coordinate bestMove = null;

		int bestMoveScore = Integer.MAX_VALUE;	
		
		//Check all of the possible moves
		for(Coordinate location : neighbors){

			ArrayList<Coordinate> movesFromThisPos = possibleMoves(location.getRow(), location.getColumn());
			if(movesFromThisPos.size() < bestMoveScore){
				bestMove = new Coordinate(location.getRow(), location.getColumn());
				bestMoveScore = movesFromThisPos.size();
			}
		}
		return bestMove;
	}
	
	
	public void printBoard(){
		
		//row
		for(int i = 0; i < BOARD_SIZE; i++){
			 System.out.println("");
     	 	 System.out.println("---------------------------------");
			//columns
			for(int j = 0; j < BOARD_SIZE; j++){
				System.out.print("| " + board[i][j]+ " ");
				//System.out.print("| " + " " + " ");
			}
			 System.out.print("|");
			//System.out.println();
		}
		System.out.println("");
    	System.out.println("---------------------------------");
	}

public class Coordinate {
	
	private int row = 0;
	private int column = 0;
	

	public Coordinate(int row, int column){
		this.row = row;
		this.column = column;
	}
	
	public int getRow(){
		return row;
	}
	
	public int getColumn(){
		return column;
	}
	
}

	public static void main(String[] args){
		KnightsTour tour = new KnightsTour();
		tour.test();
	}
}

//time complexity: O(n) where n is denoted as the size of the chessboard
//that is r * c where r is the number of rows and c is the number of columns